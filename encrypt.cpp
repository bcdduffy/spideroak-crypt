#include "crypt.hpp"

#include <iostream>

//Program to run encryption using the command line interface, checks for proper CLI formatting and passes argments to encryption library function
int main(int argc, char* argv[])
{
    if(argc == 5 && (std::string)argv[1] == (std::string)"-k" && (std::string)argv[3] == (std::string)"-m"){
        bool decrypt_success = encrypt(argv[4], argv[2]);
        if(decrypt_success){
            std::cout << "Successfully Encrypted Messasge: " << argv[4] << " Using Key: " << argv[2] << std::endl;
        }
        else {
            std::cout << "Decryption Failed, Incorrect Key" << std::endl;
        }
    }
    else {
        std::cout << "Command not recognized: Please call using format ./Decrypt -k [message_key] -m [input_message]" << std::endl;
    }
}