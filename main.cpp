#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"
#include "argsresolver.h"
using namespace std;

int main(int argc, char* argv[]) {
    ArgsResolver argsRes(argc, argv);
 
    if ((argsRes.decrypt && argsRes.encrypt) || (!argsRes.decrypt && !argsRes.encrypt)) {  // Checks if decrypt and encrypt aren't the same value 
        cerr << "Incorrect parameters!\n";
        cerr << "Usage: ./main --en -i input -k key -o output <-- for encryption\n";
        cerr << "       ./main --de -i input -k key -o output <-- for decryption";
        return 1;
    } else if (!exist(argsRes.input_file) || !exist(argsRes.key_file)) {                   // checks if input file and key file exist
        cerr << "Incorrect parameters!\n";
        cerr << "Usage: ./main --en -i input -k key -o output <-- for encryption\n";
        cerr << "       ./main --de -i input -k key -o output <-- for decryption";
        return 1;
    }
 
    if (argsRes.encrypt) {
        encode(argsRes.input_file, argsRes.key_file, argsRes.output_file);
    } else if (argsRes.decrypt) {
        decode_with_key(argsRes.input_file, argsRes.key_file, argsRes.output_file);
    }
    
    return 0;
}

bool exist(string file_path) {
    ifstream file;
    file.open(file_path.c_str());

    return bool(file);
} 

vector<int> get_ascii_key(string key_file_name) {
    ifstream key;

    vector<char> vkey;
    vector<int> ascii_vkey;

    key.open(key_file_name);
    char vkey_data;
    key >> vkey_data;
    
    while (!key.eof()) {
        vkey.push_back(toupper(vkey_data));
        key >> vkey_data;
    }

    key.close();

    for (int i=0; i < vkey.size(); i++) {
        ascii_vkey.push_back((int)vkey[i] - 65);
    }
    return ascii_vkey;
}

void encode(string input_file_name, string key_file_name, string output_file_name) {
    ifstream input;
    ofstream output;

    vector<int> ascii_vkey = get_ascii_key(key_file_name);
    int key_length = ascii_vkey.size();

    input.open(input_file_name);
    output.open(output_file_name);

    char current_char;
    int current_index = 0;
    int current_char_in_ascii;
    int new_position_in_alphabet;

    while (input >> noskipws >> current_char) {       
        if (isalpha(current_char)) {
            current_char_in_ascii = (int)toupper(current_char);
            int shift_index = current_index % key_length;

            new_position_in_alphabet = ((current_char_in_ascii + ascii_vkey[shift_index]) - 65 ) % 26;
            char shifted_char = char(new_position_in_alphabet + 65);

            output << shifted_char;
            current_index += 1;
        } else {
            output << current_char;
        } 
    }
    current_index = 0;
    
    input.close();
    output.close();
}

void decode_with_key(string input_file_name, string key_file_name, string output_file_name){
    ifstream input;
    ofstream output;

    vector<int> ascii_vkey = get_ascii_key(key_file_name);
    int key_length = ascii_vkey.size();

    input.open(input_file_name);
    output.open(output_file_name);

    char current_char;
    int current_index = 0;
    int current_char_in_ascii;


    while (input >> noskipws >> current_char) {
        if (isalpha(current_char)) {
            int shift_index = current_index % key_length;
            char shifted_char = ((int)toupper(current_char) - ascii_vkey[shift_index]);
            if (shifted_char < 65) {
                output << char(shifted_char + 26);
                current_index += 1;
            } else {
                output << char(shifted_char);
                current_index += 1;
            }
        } else {
            output << current_char;
        }
    }
    current_index = 0;
    
    input.close();
    output.close();
}