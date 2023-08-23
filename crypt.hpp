#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <sstream>



//Encryption interface, takes in parameter in_message, the message to be encrypted, and message_key, the key, returns true if encryption is successful
bool encrypt(std::string in_message, std::string message_key);

//Decryption interface, takes in parameter message_key, the key to decrypt the cyphertext, returns the plain text on success, bothing on failure
std::string decrypt(std::string message_key);

//Decryption/Encryption algorithm, returns string from Decryption/Encryption using key message pair passed as argument
std::string encrypt_decrypt(std::string msg, std::string key);