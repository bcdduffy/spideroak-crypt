#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <sstream>




bool encrypt(std::string in_message, std::string message_key);

std::string decrypt(std::string message_key);

std::string encrypt_decrypt(std::string msg, std::string key);