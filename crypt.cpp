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

    std::string cyphertext = encrypt_decrypt(in_message, message_key);
    //std::cout << "Decrypted: " << encrypt_decrypt(cyphertext, message_key) << std::endl;
    cryptFile << cyphertext << "," << message_key << "\n";
    cryptFile.close();
    return true;

}

std::string decrypt(std::string message_key){
    std::ifstream cryptFile;
    cryptFile.open("messages.csv");
    if (!cryptFile.is_open()) {
        std::cout << "Error: File failed to open" << std::endl;
    }
    std::string decrypted_string = "";
    std::string line = "";
    while(getline(cryptFile, line)) {
        std::string file_key;
        std::string file_cypher;

        std::stringstream inputString(line);

        getline(inputString, file_cypher, ',');
        getline(inputString, file_key);

        if(message_key == file_key){
            decrypted_string = file_cypher;
            break;
        }

    }

    decrypted_string = encrypt_decrypt(decrypted_string, message_key);
    cryptFile.close();
    return decrypted_string;
}



std::string encrypt_decrypt(std::string msg, std::string key)
{
    char keyChar = key[0]; 
    std::string output = msg;
    for (int i = 0; i < msg.size(); i++){
        output[i] = msg[i] ^ keyChar;
    }
    return output;
}
