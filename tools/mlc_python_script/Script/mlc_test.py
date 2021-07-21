import subprocess
mlc_app = "C:/Program Files (x86)/STMicroelectronics/Unico-GUI/unico.exe"  ## Windows

def test_arff_on_decisiontree( dectree_filename, arff_filename, testresults_filename ):
  
	print("\nCalling MLC app for testing ARFF on decision tree...")
	args = [mlc_app, "./CLI", "-MLC_test_arff", dectree_filename, arff_filename, testresults_filename]
	mlc_app_ret_value = subprocess.call(args)
	if (mlc_app_ret_value == 0):
		print("\nTest file generated successfully: " + testresults_filename)
	elif (mlc_app_ret_value == 70):
		print("\nERROR: file not found")
	else:
		print("\nERROR: ", mlc_app_ret_value)