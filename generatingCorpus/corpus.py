import os

filelist = []

allpath = os.path.abspath(r"C:\Users\Asaloy\Desktop\selflearning\araProje\glove-cbow\TrainHash")
#beningpath = os.path.abspath(r"C:\Users\ISL\Desktop\model3\trainset\Benign")
#malwarepath = os.path.abspath(r"C:\Users\ISL\Desktop\model3\trainset\Malware")
filehandlerlist = []

#for dirname, dirnames, filenames in os.walk(beningpath):
#	for filename in filenames:
#		filelist.append(os.path.join(dirname, filename))

for dirname, dirnames, filenames in os.walk(allpath):
	for filename in filenames:
		filelist.append(os.path.join(dirname, filename))


#for a in filelist:
#	print(a)


f = open("corpus.txt", "w")
for filepath in filelist:
	tmp = open(filepath)
	f.write(tmp.read())
	f.write("\n")

