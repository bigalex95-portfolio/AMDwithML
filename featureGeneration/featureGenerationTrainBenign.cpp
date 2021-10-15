//
//  main.cpp
//  pre_processingTrainBenign
//
//  Created by Alibek Erkabayev on 21.04.2019.
//  Copyright © 2019 Alibek Erkabayev. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <numeric>

using namespace std;

map< string, vector<float> > vec_list;

void getSum(vector<float> const &input,float *arraySum)
{
	for (int i = 0; i < input.size(); i++) {
		arraySum[i] = arraySum[i] + input.at(i);
	}
}

void init_vec2map(int &emdSize){
    string word;
    string code;
    ifstream file;
    float tmp;
    file.open("../outputVectors/glove2_300.txt");

    file >> word;
    char cstr[word.size() + 1];
    strcpy(cstr, word.c_str());
    int count  = atoi(cstr);

    file >> word;
    cstr[word.size() + 1];
    strcpy(cstr, word.c_str());
    emdSize  = atoi(cstr);

    for (int i = 0; i < count; i++) {
            file >> code;
            for(int j = 0; j < emdSize; j++){
                file >> word;
                char cstr[word.size() + 1];
                strcpy(cstr, word.c_str());
                tmp  = atof(cstr);
                vec_list[code].push_back(tmp);
            }
    }

    file.close();
}

int main(int argc, const char * argv[]) {

    int emdSize;
    init_vec2map(emdSize);
    float arraySum[emdSize];
    float tmp;
    int wordCount;
    map< string, vector<float> >::iterator itr;

    //Source Path
    string src_path = "../TrainHash/";


    //Destination Path
    //string dest_pat = "";

    ofstream output;
    output.open("featuresTrainBenign.txt");

    ifstream file_list;
    file_list.open("../gettingFileList/file_list_train_Benign.txt");

    while(!file_list.eof()){
        string code;
        string file_name ;
        file_list >> file_name;
        cout << file_name << "\n";

        string src_file;
        src_file = src_path + file_name;
        ifstream input;
        input.open(src_file.c_str());

        wordCount = 0;
        fill_n(arraySum, emdSize, 0);
        while(!input.eof()){
            input >> code;
            itr = vec_list.find(code);
            getSum(itr->second,arraySum);
            wordCount++;
        }
        for(int i=0; i < emdSize; i++){
            arraySum[i] = arraySum[i] / wordCount;
            output << arraySum[i] << " ";
        }
        output << "Benign\n";
        input.close();
    }

    output.close();
    file_list.close();
    return 0;
}
