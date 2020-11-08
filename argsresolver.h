/** @file  */

#ifndef ARGRESOLVER_H
#define ARGRESOLVER_H

#include <string>

 /** This class is used to get and store user input as options and arguments from console. */
class ArgsResolver {
    public:
        std::string input_file = "";        ///< variable for storing input file
        std::string key_file = "";          ///< variable for storing key file
        std::string output_file = "";       ///< variable for storing output file
        bool encrypt = false;               ///< bool value for checking if user want to encode or decode text
        bool decrypt = false;               ///< bool value for checking if user want to encode or decode text
   
        ArgsResolver(int argc, char* argv[]);
 
};

#endif