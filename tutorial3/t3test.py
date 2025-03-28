#!/usr/bin/python3
import os
import signal
import sys
import tempfile
import subprocess
import glob
import shutil
import re
import time
import csv
import threading


'''
This class takes the place of sys.stdout. It intercepts whatever is
being written to the console and writes it the console, a file, and
a local data structure.
In other words, whatever you print here or in your program also
prints to the file and to a list. The list can then be searched for 
proper output. 
'''
class Tee(object):
	def open(self, name, mode):
		sys.stdout.flush()
		self.file = open(name, mode)
		self.stdout = sys.stdout
		sys.stdout = self
		#self.data = []
	def close(self):
		sys.stdout = self.stdout
		self.file.close()
	def write(self, data):
		self.file.write(data)
		self.stdout.write(data)
		#if data != '\n':
			#self.data.videoend(data)
	def flush(self):
		self.file.flush()
		self.stdout.flush()
		
verbose = True

def extract_number_from_phrase(phrase, text):
    """
    Extracts the number in the specified phrase from the given text.

    Args:
        phrase (str): The phrase to search for, including placeholders like "{number}".
        text (str): The text in which to search.

    Returns:
        int or None: The extracted number, or None if not found.
    """
    
    # Search for the pattern in the text
    match = re.search(phrase, text)

    if match:
        return int(match.group(1))
    return None


def kill_proc(proc, timeout):
	# you must have done something wrong
	# to end up here
	timeout["value"] = True
	proc.kill()

# a run with timeout function 
def run_with_timeout(cmd, timeout_sec, stdinput):
	#print("Running: ",cmd)
	proc = subprocess.Popen(cmd,stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	timeout = {"value": False}
	timer = threading.Timer(timeout_sec, kill_proc, [proc, timeout])
	timer.start()
	(out, err) = proc.communicate(input = stdinput.encode("utf-8"))
	out = out.decode("utf-8")
	err = err.decode("utf-8")
	if len(out) < 2000:
		print(out)
	else:
		#wow you printed a lot of stuff
		print(out[:2000] + "...")
	if verbose:
		print(err)
	timer.cancel()
	return proc.returncode, timeout["value"], out, err

	
def run(cmd, time, stdinput="", testPhrase = "Your score is (\d+)"):
	#print("Running: {}\n".format(cmd))
	print("Executing: {}".format(" ".join(cmd)))
	try:
		
		# just in case we will kill your process 
		# after <time> seconds
		res, timeout, out, err = run_with_timeout(cmd, time, stdinput)
	except:
		print("An exception occurred")
		print("{} test failed!".format(" ".join(cmd)))
		return 0
	if timeout:
		print("Taking too long, abort")
		print("Could be an infinite loop or segmentation fault")
		return 0
	if res == 0:
		# program ran and nothing crashed. Check the output
		score = extract_number_from_phrase(testPhrase, out)
		if score:
			print("Program exited with zero status, test passed")
			return score
		else:
			print("Program exited with zero status, test failed")
			return 0
	else: 
		print("Program exited with non-zero status, test failed")
	return 0

def test(dirname, outof):

	
	#switch to directory dirname
	os.chdir(dirname)
	sys.stdout.flush()
	print("\n{stars}\n* Compilation\n{stars}".format(stars="*"*75))
	
	# run the 'make clean' and 'make all' commands
	cmds = ["clean","all"]
	for c in cmds:
		cmd = ["make",c]
		print("Executing: {}".format(" ".join(cmd)))
		res = subprocess.call(cmd)
		sys.stdout.flush()
		if res:
			# make command produced an error
			# return with 0 marks
			print("make: non-zero exit status {}".format(res))
			#print("\n\n{stars}\n* Mark: {mark}/{outof}\n".format(stars="*"*75, mark=0, outof=outof))
			#return
		
	score = 0

	output1 = "All constructor tests complete. Your score is (\d+)/4"
	output2 = "All setter tests complete. Your score is (\d+)/7"
	print("\nTesting RGB constructor\n")
	score += run(["./test"], 5, '0', output1) 
	print("\nTesting RGB setters\n")
	score += run(["./test"], 5, '1', output2)
	

	print("\n\n{stars}\n* Mark: {mark}/{outof}\n{stars}\n".format(stars="*"*75, mark=score, outof=outof))



	

def process_all():
	
			
	t = Tee()
	
	
	
	t.open('results.txt', 'w')
	
	dirname = 'tutorial3'
	test(dirname, 11)
		
	t.close()




if __name__ == "__main__":
	
	sys.stdout.flush()
	process_all()
	sys.stdout.flush()
	
