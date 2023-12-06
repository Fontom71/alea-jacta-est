#include <iostream>
#include "basicencrypt.h"

int main() {
    BasicEncrypt basicEncrypt;

    std::string message = "Hello, World!";
    std::cout << "Message en clair : " << message << std::endl;
    
    std::string cipherText = basicEncrypt.encode(message);
    std::cout << "Message chiffré : " << cipherText << std::endl;

    std::string decodedText = basicEncrypt.decode(cipherText);
    std::cout << "Message déchiffré : " << decodedText << std::endl;

    return 0;
}
