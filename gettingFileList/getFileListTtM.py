import glob

#path where your source files
MALWARE_PATH_TEST = '../Malware/Test/'

#opening and putting to list array all sources file names
class_malware_test = glob.glob(MALWARE_PATH_TEST + '*.txt')

#writing all source file names to fileList.txt
with open('file_list_test_Malware.txt', 'w') as f:
    for item in class_malware_test:
        f.write("%s\n" % item)

f.close()
