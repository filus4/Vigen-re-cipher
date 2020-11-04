#include <string>
 
class ArgsResolver {
    public:
        std::string input_file = "";        // Setting basic values because c++ can't do it by itself
        std::string key_file = "";          // and sets trash numbers instead
        std::string output_file = "";
        bool encrypt = false;
        bool decrypt = false;
   
        ArgsResolver(int argc, char* argv[]);
 
};