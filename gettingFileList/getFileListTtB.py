import glob

#path where your source files
BENIGN_PATH_TEST = '../Benign/Test/'

#opening and putting to list array all sources file names
class_benign_test = glob.glob(BENIGN_PATH_TEST + '*.txt')

#writing all source file names to fileList.txt
with open('file_list_test_Benign.txt', 'w') as f:
    for item in class_benign_test:
        f.write("%s\n" % item)

f.close()
