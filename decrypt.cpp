#include "crypt.hpp"
#include <iostream>
int main(int argc, char* argv[])
{
    if(argc == 2){
        std::string output = decrypt(argv[1]);
        if(output == ""){
            std::cout << "Error: Key not found" << std::endl;
            return 1;
        }
        else {
            std::cout << "Out:" << output << std::endl;
            return 0;
        }
    }
    else {
        std::cout << "Invalid number of command line arguments: Please call using format ./Decrypt [message_key]" << std::endl;
        return 1;
    }
}