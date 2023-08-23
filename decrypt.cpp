//#include "crypt.h"
#include <iostream>
int main(int argc, char* argv)
{
    if(argc == 2){

        return 0;
    }
    else {
        std::cout << "Invalid number of command line arguments: Please call using format ./Decrypt [message_key]" << std::endl;
        return 1;
    }
}