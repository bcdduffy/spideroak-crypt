#include "crypt.hpp"

#include <iostream>
int main(int argc, char* argv[])
{
    if(argc == 3){
        bool decrypt_success = true;
        if(decrypt_success){
            //std::cout << "ARGUMENT: " << argv[1] << std::endl;

            encrypt(argv[1], argv[2]);
        }
        else {
            std::cout << "Decryption Failed, Incorrect Key" << std::endl;
        }
    }
    else {
        std::cout << "Invalid number of command line arguments: Please call using format ./Decrypt [input_message] [message_key]" << std::endl;
    }
}