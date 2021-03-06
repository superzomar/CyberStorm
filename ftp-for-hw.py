######################################################
# Group: Greed
# Members: Alexandra Duran Chicas, Zachary Guillot, 
# Conan Howard, Oluwatoyosi Kade, Michael Mahan, 
# Darryl Rayborn, Jonathan Ruppel, Samantha Santiago
# Date: 04/03/2018
# Program: ftp.py
# Objective: Takes the permissions gathered from a directory in
# an FTP, translates them into binary, and then decodes it to
# reveal a covert message.
######################################################
import ftplib

def solve(n):
##################################################################################
	# fetch file listing, permissions from FTP --> done
	# reference: https://stackoverflow.com/questions/111954/using-pythons-ftplib-to-get-a-directory-listing-portably
	# up until I introduce f.
	ftp = ftplib.FTP("jeangourd.com")
	ftp.login("anonymous", "") # logs in
	ftp.cwd(n)

	data = []
	
	ftp.dir(data.append) # takes directory info and adds it to data list above

	ftp.quit() # gets out of the FTP
	# get it to export to a list instead of outputting to the command line --> done
	f = ''
	# hardcoded to be specific for directory 10. Otherwise, it checks to see if bits are set before adding the rightmost seven bits to f
	for line in data:
		if n == "10":
			f += (line[0:10])
		else:
			if line[0:3] == "---":
				f += (line[3:10])
################################################################################# 
	# Read a certain segment of the string, then have an if/else statement that turns - into 0 and drwx into 1's --> done
	g = ''

	for i in f:
		if (i == "r" or i == "w" or i == "x" or i == "d"):
			g += "1"
		elif (i == "-"):
			g += "0"
#################################################################################
	# decode file permissions with binary decoder --> done
	# I took the code from the part of my binary program where it processes 7-bits and pasted it here - Samantha Santiago
	len_seven = 7
	charac = ''.join(g.split()) # string of what's in the file
	input_str = [charac[i:i+len_seven] for i in range(0,len(charac),len_seven)]
	lista = ''.join([chr(int(c,base=2)) for c in input_str]) # holds decoded string
	print lista
#################################################################################
	# send decoded message to output --> done
#################################################################################
# calls function to solve for directories 7 and 10
#solve('~')
solve("7")
solve("10")
#################################################################################
