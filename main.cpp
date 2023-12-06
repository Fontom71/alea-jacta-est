#include <iostream>
#include "basicencrypt.h"
#include "caesar.h"

int main() {
    // BASICENCRYPT //
    BasicEncrypt basicEncrypt;

    std::string message = "les sanglots longs des violons de l'automne blessent mon coeur d'une langueur monotone.";
    std::cout << "Message en clair : " << message << std::endl;
    
    // Chiffrement
    std::string cipherText = basicEncrypt.encode(message);
    std::cout << "Message chiffré : " << cipherText << std::endl;

    // Déchiffrement
    std::string decodedText = basicEncrypt.decode(cipherText);
    std::cout << "Message déchiffré : " << decodedText << std::endl;

    // CAESAR //
    Caesar caesar(3);

    // Chiffrement
    std::string cipherCaesar = caesar.encode(message);
    std::cout << "Message chiffré : " << cipherCaesar << std::endl;
    caesar.write("caesar.txt", cipherCaesar);

    // Déchiffrement
    std::string decodedCaesar = caesar.decode(caesar.read("caesar.txt"));
    std::cout << "Message déchiffré : " << decodedCaesar << std::endl;

    std::cout << "Chiffrement et déchiffrement réussis." << std::endl;

    return 0;
}
