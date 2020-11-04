#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functions.h>
using namespace std;

// TODO:
// 1 - check if files passed to the program exist
// 2 - describe all functions in doxygen style
// 3 - make project report

class ArgsResolver {
    public:
        string input_file;
        string key_file;
        string output_file;
        bool encrypt, decrypt; 
   
        ArgsResolver(int argc, char* argv[]) {
            for (int i = 1; i < argc; i++) {
                if (argv[i] == "--en") {
                    encrypt = true;
                } else if (argv[i] == "--de") {
                    decrypt = true;
                } else if (argv[i] == "-k") {
                    if (i + 1 < argc) {
                        key_file = argv[++i];
                    }
                } else if (argv[i] == "-i") {
                      if (i + 1 < argc) {
                        input_file = argv[++i];
                    }
                } else if (argv[i] == "-o") {
                       if (i + 1 < argc) {
                         output_file = argv[++i];
                    }
                }
            }                          
};

bool exist(string file_path) {
            ifstream file;
            file.open(file_path.c_str());

            return bool(file);
} 

int main(int argc, char* argv[]) {

    ArgsResolver blabla();

    if (encrypt) {
        encode(input_file, key_file, output_file);
    } else if (decrypt) {
        decode_with_key(input_file, key_file, output_file);
    }
    
    return 0;
}