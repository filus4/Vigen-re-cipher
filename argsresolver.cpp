#include <string>
#include <iostream>
#include "argsresolver.h"
 
using namespace std;
 
ArgsResolver::ArgsResolver(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "--en") {
            encrypt = true;
        } else if (string(argv[i]) == "--de") {
            decrypt = true;
        } else if (string(argv[i]) == "-k") {
            if (i + 1 < argc) {
                key_file = argv[++i];
            }
        } else if (string(argv[i]) == "-i") {
            if (i + 1 < argc) {
                input_file = argv[++i];
            }
        } else if (string(argv[i]) == "-o") {
            if (i + 1 < argc) {
                output_file = argv[++i];
            }
        }
    }
}