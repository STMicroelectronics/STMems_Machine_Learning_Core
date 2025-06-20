import re
import pandas as pd
from scipy.io import arff

DECTREE_IN   = "dectree.txt"
SAMPLE_SIZES = "sample_size.txt"
NEW_ARFF     = "features.arff"
DECTREE_OUT  = "dectree_updated.txt"

ref_count = {}
with open(SAMPLE_SIZES) as f:
    for line in f:
        cls, cnt = line.strip().split()
        ref_count[cls] = int(cnt)

data, meta = arff.loadarff(NEW_ARFF)
df_new = pd.DataFrame(data)
if df_new["class"].dtype == object and isinstance(df_new["class"].iloc[0], bytes):
    df_new["class"] = df_new["class"].str.decode("utf-8")

new_high = df_new[df_new["class"] == "high"]["F1_PEAK_TO_PEAK_ACC_V2"].astype(float).values
new_n    = len(new_high)
ref_n    = ref_count.get("high", 0)

old_thr = None
thr_pattern = re.compile(r"\|\s*F1_PEAK_TO_PEAK_ACC_V2\s*>\s*([\d\.]+):\s*high")
with open(DECTREE_IN) as f:
    for L in f:
        m = thr_pattern.search(L)
        if m:
            old_thr = float(m.group(1))
            break

if old_thr is None:
    raise RuntimeError("Can't find the high threshold")

new_rep = new_high.mean() if new_n>0 else old_thr
new_thr = (ref_n * old_thr + new_n * new_rep) / (ref_n + new_n)
new_thr2 = old_thr + (((new_n * 4) / ref_n) * (new_rep - old_thr))

print(new_thr)
print(new_thr2)

med_pat  = re.compile(r"^(\|\s*F1_PEAK_TO_PEAK_ACC_V2\s*<=\s*)([\d\.]+)(\s*:\s*medium)$")
high_pat = re.compile(r"^(\|\s*F1_PEAK_TO_PEAK_ACC_V2\s*>\s*)([\d\.]+)(\s*:\s*high)$")

out_lines = []
with open(DECTREE_IN) as f:
    for L in f:
        if med_pat.search(L):
            L = med_pat.sub(lambda m: f"{m.group(1)}{new_thr:.2f}{m.group(3)}", L)
        elif high_pat.search(L):
            L = high_pat.sub(lambda m: f"{m.group(1)}{new_thr:.2f}{m.group(3)}", L)
        out_lines.append(L)

with open(DECTREE_OUT, "w") as f:
    f.writelines(out_lines)

print("Old threshold:", old_thr)
print("New samples:", new_n, "Ref samples:", ref_n)
print("New rep. value (mean):", new_rep)
print("New threshold:", round(new_thr, 4))
print(f"Updated tree written to {DECTREE_OUT}")
