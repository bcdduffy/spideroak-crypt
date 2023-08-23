#include "crypt.hpp"
#include <iostream>

//Program to run decryption using the command line interface, checks for proper CLI formatting and passes argments to decryption library function
int main(int argc, char* argv[])
{
    if(argc == 3 && (std::string)argv[1] == (std::string)"-k"){
        std::string output = decrypt(argv[2]);
        if(output == ""){
            std::cout << "Error: Key not found" << std::endl;
            return 1;
        }
        else {
            std::cout << output << std::endl;
            return 0;
        }
    }
    else {
        std::cout << "Invalid command line argument: Please call using format ./Decrypt -k [message_key]" << std::endl;
        return 1;
    }
}