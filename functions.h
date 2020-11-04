#include <vector>
#include <string>

bool exist(std::string file_path);

std::vector<int> get_ascii_key(std::string key_file_name);

void encode(std::string input_file_name, std::string key_file_name, std::string output_file_name);

void decode_with_key(std::string input_file_name, std::string key_file_name, std::string output_file_name);