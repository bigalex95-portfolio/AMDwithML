import glob

#path where your source files
BENIGN_PATH_TRAIN = '../Benign/Train/'

#opening and putting to list array all sources file names
class_benign_train = glob.glob(BENIGN_PATH_TRAIN + '*.txt')

#writing all source file names to fileList.txt
with open('file_list_train_Benign.txt', 'w') as f:
    for item in class_benign_train:
        f.write("%s\n" % item)

f.close()
