/** @file  */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

#include "argsresolver.h"


/** The function chcecks if file passed to it esists.
@param file_path name of the file
@return bool value 
 */
bool exist(std::string file_path);

/** The function iterates through the file and adds each value into vector. The function transformates values from vector using values from ascii table.
@param key_file_name name of the key file
@return vector filled with modified values
 */
std::vector<int> get_ascii_key(std::string key_file_name);

/** The function takes plaintext. The function modifies it by moving each letter by a certain number.
@param input_file_name name of the input file
@param key_file_name name of the key file
@param output_file_name name of the output file
@return cyphertext
 */
void encode(std::string input_file_name, std::string key_file_name, std::string output_file_name);

/** The function takes cyphertext. The function modifies it by moving each letter by a certain number.
@param input_file_name name of the input file
@param key_file_name name of the key file
@param output_file_name name of the output file
@return plaintext
 */
void decode_with_key(std::string input_file_name, std::string key_file_name, std::string output_file_name);

#endif