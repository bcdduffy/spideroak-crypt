This is a short manual page for how to operate the two programs and how they work.
This was built using CMake and C++

The project specification indicatees that there should be two programs, both called using the command line interface. One to encrypt a message with a passed key, and the other to print a decrypted message of the text maatching a key passed. These two programs are supposed to interface using a common library holding the encryption and decryption logic. 

Looking at the problem as a whole my systems solutions is as follows:
Becuase both need to be separate programs and need to be intercaed with using hte command line both the encrytion and decryption program would need to be separate executables and separate project. The common library that both will used will have to be its own made library separate from the two, and linked statically at compile time. Because the two programs are invoked at different run time instances, storage would probably have to be used to hold the messages and keys to allow the holding the information outside of specific runtime instances of the programs.

The system architecture:
There are two executables, Encrypt, and Decrypt, both are statically linked to a library crypt which when adding and taking out encrypted messages uses a messages.csv file to hold the message key pairs.

Encryption:
Encrypt will check the command line arguments passed to it and will call the library function encrypt passing the message and key as arguments. It will perform the encryption using an XOR encryption and store the cyphertext, key pair in messages.csv

Decryption:
Decrypt will check the command line arguments passed to it and will call the library function decrypt passing the key as an argument. It will search messages.csv for the first instance of the key passed and perform a cecryption of the cyphertext paired with the key using the XOR decryption.

HOW TO USE:
To build, with Cmake installed properly you can go to the root folder and call:
cmake --build .

Both programs are built to the Debug folder, in there should be the two executables, Decrypt, and Encrypt

The CLI for Encryption: 
$ <program1name> -k <key> -m <message>  # Initiate encryption for program 1
From the root in Windows an example would be:       ./Debug/Encrypt -k hellokey -m hellomessage     
This will print a success message showing the key and message


Decryption:
$ <program2name> -k <key>               # Decrypt the message and output the plaintext
From the root in Windows an example would be:       ./Debug/Decrypt -k hellokey
This will print the decrypted message to the terminal
