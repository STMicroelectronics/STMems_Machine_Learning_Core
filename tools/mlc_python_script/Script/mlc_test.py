import subprocess
import logging

from mlc_configurator import MLC_TOOL_EXECUTABLE


def test_arff_on_decisiontree(
    dectree_filename: str,
    arff_filename: str,
    testresults_filename: str,
    validate_results: bool = True
) -> None:
    logging.info("\nCalling MLC app for testing ARFF on decision tree...")
    proc = subprocess.run(
        args=[
            MLC_TOOL_EXECUTABLE,
            "dtt",
            dectree_filename,
            "--arff",
            arff_filename,
            "--arff-stats" if validate_results else "--pred-stats",
        ],
        stdout=subprocess.PIPE,
        check=False
    )
    if proc.returncode == 0:
        logging.info("\nTest file generated successfully: %s",
                     testresults_filename)
    else:
        logging.error("\nERROR: %s", proc.returncode)
    with open(testresults_filename, "wb") as f:
        f.write(proc.stdout)
