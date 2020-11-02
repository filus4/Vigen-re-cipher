#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

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

int main(int argc, char* argv[]) {

    string input_file;
    string key_file;
    string output_file;
    bool encrypt, decrypt;


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

    if (encrypt) {
        encode(input_file, key_file, output_file);
    } else if (decrypt) {
        decode_with_key(input_file, key_file, output_file);
    }
    
    return 0;
}