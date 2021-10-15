//
//  main.cpp
//  pre_processingTestMalware
//
//  Created by Alibek Erkabayev on 21.04.2019.
//  Copyright © 2019 Alibek Erkabayev. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;


map<string, string> op_list;

void init_hashmap(){
    string code;
    string hash;
    ifstream file;
    file.open("hash_table.txt");

    for (int i = 0; i < 238; i++) {
        file >> code;
        file >> hash;
        op_list[code] = hash;
    }

    file.close();
}



int main(int argc, const char * argv[]) {



    init_hashmap();


    //Source Path
    string src_path = "../Malware/Test/";
    int strIndex = 0;


    //Destination Path
    string dest_path = "../TestHash/";

    ifstream file_list;

	//opening file where listing all the fileNames from source path
    file_list.open("../gettingFileList/file_list_test_Malware.txt");

    while(!file_list.eof()){
        int counter = 0;
        string file_name ;
        file_list >> file_name;
        string src_file, dst_file;
        src_file = src_path + file_name;
        dst_file = dest_path + file_name;

        ifstream input;
        ofstream output;
        string line;
        string hash;

        cout << dst_file << endl;
		//if you have C++11 or higher version of gcc use input.open(src_file);
        //if you don't have acces to C++11 or higher version of gcc use input.open(src_file.c_str());
        input.open(src_file.c_str());
        output.open(dst_file.c_str());
        int file_number = 0;
        while (getline(input, line)) {
            //input >> line;
            //cout << line << endl;
            if(!line.compare("FUNCFLAG")){
                output << "\n";
                counter = 0;
            }
            else{
                hash = op_list[line];
                if(hash == " "){
                    cout << "ERROR:" << line << "--" << "File Name" << file_name << endl;
                }
                else{
                    if(counter == 0 ){
                        output << hash;
                        counter ++;
                    }
                    else{
                        output << " " << hash;
                    }
                }
            }

            file_number++;
            if(file_number % 100 == 0){
                cout << " File Number " << file_number << endl;
            }

        }
        
        //printing current fileName
        //cout << file_name << endl;

        input.close();
        output.close();

    }


    file_list.close();
    return 0;
}
