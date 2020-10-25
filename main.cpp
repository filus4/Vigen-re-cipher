#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


// Function to make whole sentence uppercase
string make_it_upper(string sentence) {
    for (auto & c: sentence) {
        c = toupper(c);
    }
    return sentence;
}

void print_number(vector<int> const &a) {
   cout << "The vector elements are: ";

   for (int i=0; i < a.size(); i++) {
        cout << '[' << a.at(i) << ']';
   }
}

void print_charakter(vector<int> const &a) {
   cout << "The vector elements are: ";

   for (int i=0; i < a.size(); i++) {
        cout << '[' << a.at(i) << ']';
   }
}


int main() {
    
//  char x;
//  cin >> x;
    
//   int ascii = (int)x;

//   cout << "In ascii table letter [" << x << "] " << "is equal to: " << ascii;

    ifstream input, key;
    ofstream output;

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

    int key_length = vkey.size();

    for (int i=0; i < vkey.size(); i++) {
        ascii_vkey.push_back((int)vkey[i] - 65);
    }

    input.open("input.txt");
    output.open("output.txt");

    char current_char;
    int current_index;
    current_index = 0;
    int current_char_in_ascii;
    int new_position_in_alphabet;

    while (!input.eof()) {
        char current_char;
        input >> noskipws >> current_char;

        output << current_char;
        
        if (isalpha(current_char)) {
            current_char_in_ascii = (int)toupper(current_char);

            int shift_index = current_index % key_length;

            new_position_in_alphabet = ((current_char_in_ascii + ascii_vkey[shift_index]) - 65 ) % 26;
            char charakter = char(new_position_in_alphabet + 65);

           // output << charakter;

            current_index += 1;
        } else if (!isalpha(current_char)) {
            current_index += 1;
        } 
    }

    current_index = 0;
    
    
    input.close();
    output.close();


    print_number(ascii_vkey);
    cout << endl;
    cout << "Size of the given vector is: " << ascii_vkey.size();

    return 0;
}