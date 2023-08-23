#include "crypt.hpp"

struct {
std::string cyphertext;
std::string key;
} encrypted_struct;


bool encrypt(std::string in_message, std::string message_key){
    std::ofstream cryptFile;
    cryptFile.open("messages.csv", std::ios::app);
    if (!cryptFile.is_open()) {
        std::cout << "Error: File failed to open" << std::endl;
        return false;
    }
    std::string cyphertext = encrypt_algorithm(in_message, message_key);
    cryptFile << cyphertext << "," << message_key << "\n";
    cryptFile.close();
    return true;
}

bool decrypt(std::string message_key){
    std::ofstream cryptFile;
    cryptFile.open("C:\\messages.csv");
    if (!cryptFile.is_open()) {
        std::cout << "Error: File failed to open" << std::endl;
    }

    while(cryptFile.good()) {
        
    }

    return true;
}



std::string encrypt_algorithm(std::string msg, std::string key)
{
    // Make sure the key is at least as long as the message
    std::string tmp(key);
    while (key.size() < msg.size())
        key += tmp;
    
    // And now for the encryption part
    for (std::string::size_type i = 0; i < msg.size(); ++i)
        msg[i] ^= key[i];
    return msg;
}
std::string decrypt_algorithm(std::string msg, std::string key)
{
    return encrypt_algorithm(msg, key); // lol
}