#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void print_number(vector<int> const &a) {
   cout << "The vector elements are: ";

   for (int i=0; i < a.size(); i++) {
        cout << '[' << a.at(i) << ']';
   }
}

vector<int> get_ascii_key(string file_name) {
    ifstream key;

    vector<char> vkey;
    vector<int> ascii_vkey;

    key.open("key.txt");
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

void encode() {
    ifstream input;
    ofstream output;

    vector<int> ascii_vkey = get_ascii_key("key.txt");

    int key_length = ascii_vkey.size();

    input.open("encode_input.txt");
    output.open("encode_output.txt");

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

void decode_with_key(){
    ifstream input;
    ofstream output;

    vector<int> ascii_vkey = get_ascii_key("key.txt");
    int key_length = ascii_vkey.size();

    input.open("encode_output.txt");
    output.open("decode_output.txt");

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

int main() {
    
    encode();

    decode_with_key();

    return 0;
}