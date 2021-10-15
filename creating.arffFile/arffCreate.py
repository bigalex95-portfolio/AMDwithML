print("----------\n\n Starting Creating ARFF File \n\n ----------")

my_file = open("train_model_cbow2_300BM.arff","w")
my_file.write("@RELATION MODEL\n")   

for i in range(0,300):
	my_file.write("@ATTRIBUTE feature" + str(i+1) + " NUMERIC\n")

my_file.write("@ATTRIBUTE class " + " {Benign,")
with open('family_list.txt') as file:
        my_lines = file.readlines();
        for line in my_lines:
                line = line.replace("\n",",")
                my_file.write(line)
        my_file.write("}\n")
my_file.write("@DATA\n")

with open('../featureGeneration/featuresTrainMalware.txt') as file:
        my_lines = file.readlines();
        for line in my_lines:
                line = line.replace(" ",",").replace("\n","")
                my_file.write(line)
                my_file.write("\n")

with open('../featureGeneration/featuresTrainBenign.txt') as file:
        my_lines = file.readlines();
        for line in my_lines:
                line = line.replace(" ",",").replace("\n","")
                my_file.write(line)
                my_file.write("\n")
my_file.close()
print("Finishing Train File")

my_file = open("test_model_cbow2_300BM.arff","w")
my_file.write("@RELATION MODEL\n")   

for i in range(0,300):
	my_file.write("@ATTRIBUTE feature" + str(i+1) + " NUMERIC\n")

my_file.write("@ATTRIBUTE class " + " {Benign,")
with open('family_list.txt') as file:
        my_lines = file.readlines();
        for line in my_lines:
                line = line.replace("\n",",")
                my_file.write(line)
        my_file.write("}\n")
my_file.write("@DATA\n")

with open('../featureGeneration/featuresTestMalware.txt') as file:
        my_lines = file.readlines();
        for line in my_lines:
                line = line.replace(" ",",").replace("\n","")
                my_file.write(line)
                my_file.write("\n")

with open('../featureGeneration/featuresTestBenign.txt') as file:
        my_lines = file.readlines();
        for line in my_lines:
                line = line.replace(" ",",").replace("\n","")
                my_file.write(line)
                my_file.write("\n")
my_file.close()
print("Finishing Test File")
