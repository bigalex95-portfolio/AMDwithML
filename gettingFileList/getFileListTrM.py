import glob

#path where your source files
MALWARE_PATH_TRAIN = '../Malware/Train/'

#opening and putting to list array all sources file names
class_malware_train = glob.glob(MALWARE_PATH_TRAIN + '*.txt')

#writing all source file names to fileList.txt
with open('file_list_train_Malware.txt', 'w') as f:
    for item in class_malware_train:
        f.write("%s\n" % item)

f.close()
