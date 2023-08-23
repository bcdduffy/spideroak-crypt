#include "crypt.hpp"



/*
The encrypt function will take in two parameters, in_message, and message_key, and will try to encrypt the 
message using the key provided writing the cypher text, key pair to a csv file for storage. If this is 
successful it will return true

std::string in_message - string representing the message to be encrypted

std::string message_key - string representing the key to be used to generate the cypthertext

*/
bool encrypt(std::string in_message, std::string message_key){



    std::ofstream cryptFile;
    cryptFile.open("messages.csv", std::ios::app);
    if (!cryptFile.is_open()) {
        std::cout << "Error: File failed to open" << std::endl;
        return false;
    }
    
    std::string cyphertext = encrypt_decrypt(in_message, message_key);
    cryptFile << cyphertext << "," << message_key << "\n";
    cryptFile.close();
    return true;

}

/*
The decrypt function will take a single parameter, the key, to use to find the cypher text and perform decryption.
The funciton will search the csv file for the first matching key and will perform decryption onn the cypher text 
found in the cyphertet, key pair. It will then return the decrypted message If not found it will return an empty string.

std::string message_key - string representing the key to be used to locate and decode the cyphertext

*/
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


/*
The encrypt_decrypt function is used to perfomr the encryption and decry[tion of the cyphertext. The function
will take in as two parameters the message and key and perform an XOR encryption on the text, returning the encrypted
or decrypted string. THe algorithm uses and XOR encyptuion algoritm which is reversible making it work both as an
encryption and decryption algorithm.

std::string msg - the message either as plaintext, or cyphertext, to be modified

std::string key - the key used to perform the encrption/decryption algorithm

*/
std::string encrypt_decrypt(std::string msg, std::string key)
{
    char keyChar = key[0]; 
    std::string output = msg;
    for (int i = 0; i < msg.size(); i++){
        output[i] = msg[i] ^ keyChar;
        
    }
    return output;
}
