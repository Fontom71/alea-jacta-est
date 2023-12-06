#include <iostream>
#include <fstream>
#include "basicencrypt.h"
#include "caesar.h"
#include "caesar2.h"
#include "vigenere.h"

int main() {
    // BASICENCRYPT //
    std::cout << "BASICENCRYPT" << std::endl;
    BasicEncrypt basicEncrypt;

    std::string message = "Les sanglots longs Des violons De l'automne Blessent mon coeur D'une langueur Monotone.";
    std::cout << "Message en clair : " << message << std::endl;
    
    // Chiffrement
    std::string cipherText = basicEncrypt.encode(message);
    std::cout << "encrypt : " << cipherText << std::endl;

    // Déchiffrement
    std::string decodedText = basicEncrypt.decode(cipherText);
    std::cout << "decrypt : " << decodedText << std::endl;

    // CAESAR //
    std::cout << "CAESAR" << std::endl;
    Caesar caesar(3);

    // Chiffrement
    std::string cipherCaesar = caesar.encode(message);
    std::cout << "encrypt : " << cipherCaesar << std::endl;
    caesar.write("caesar.txt", cipherCaesar);

    // Déchiffrement
    std::string decodedCaesar = caesar.decode(caesar.read("caesar.txt"));
    std::cout << "decrypt : " << decodedCaesar << std::endl;

    // CAESAR2 //
    std::cout << "CAESAR2" << std::endl;
    Caesar2 caesar2(3);

    // Lecture
    std::ifstream inputFile("phrases.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier phrases.txt." << std::endl;
        return 1;
    }

    // Chiffrement
    std::string line;
    std::string cipherCaesar2;
    while (std::getline(inputFile, line)) {
        cipherCaesar2 += caesar2.encode(line) + "\n";
    }
    inputFile.close();

    // Ecriture
    caesar2.write("caesar2.txt", cipherCaesar2);
    std::cout << "encrypt : " << cipherCaesar2 << std::endl;

    // Déchiffrement
    std::string decodedCaesar2 = caesar2.decode(caesar2.read("caesar2.txt"));
    std::cout << "decrypt : " << decodedCaesar2 << std::endl;

    // VIGENERE //
    std::cout << "VIGENERE" << std::endl;
    Vigenere vigenere("turing");
    std::string cipherVigenere = vigenere.encode(message);
    std::cout << "encrypt : " << cipherVigenere << std::endl;
    std::string decodedVigenere = vigenere.decode(cipherVigenere);
    std::cout << "decrypt : " << decodedVigenere << std::endl;

    std::cout << "encrypt and decrypt success" << std::endl;

    return 0;
}
