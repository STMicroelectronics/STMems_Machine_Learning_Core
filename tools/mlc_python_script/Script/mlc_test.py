import subprocess
import logging


def test_arff_on_decisiontree(
    dectree_filename: str,
    arff_filename: str,
    testresults_filename: str,
    validate_results: bool = True
):
    logging.info("\nCalling MLC app for testing ARFF on decision tree...")
    proc = subprocess.run(
        args=[
            "mlc_configuration_tool.exe",
            "dtt",
            dectree_filename,
            "--arff",
            arff_filename,
            "--arff-stats" if validate_results else "--pred-stats"
        ],
        stdout=subprocess.PIPE,
        check=False
    )
    if proc.returncode == 0:
        logging.info(f"\nTest file generated successfully: {testresults_filename}")
    else:
        logging.error(f"\nERROR: {proc.returncode}")
    with open(testresults_filename, "wb") as f:
        f.write(proc.stdout)
