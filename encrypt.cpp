#include "encrypt.h"
#include <fstream>
#include <iostream>

std::string Encrypt::encode(const std::string & plain)
{
    return std::string();
}

std::string Encrypt::decode(const std::string & cipher)
{
    return std::string();
}

void Encrypt::write(const std::string& fileName, const std::string& data) {
    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        outputFile << data;
        outputFile.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier " << fileName << std::endl;
    }
}

std::string Encrypt::read(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    std::string content;
    if (inputFile.is_open()) {
        content.assign(std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>());
        inputFile.close();
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier " << fileName << std::endl;
    }
    return content;
}