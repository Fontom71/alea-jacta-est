// caesar.cpp
#include "caesar.h"
#include <cctype>

Caesar::Caesar(int shift) : shift(shift) {}

std::string Caesar::encode(const std::string& plainText) {
    std::string _cypher = plainText;

    for (char& c : _cypher) {
        if (std::isalpha(c) && std::islower(c)) {
            c = 'a' + (c - 'a' + shift) % 26;
        }
    }

    return _cypher;
}

std::string Caesar::decode(const std::string& cipherText) {
    std::string result = cipherText;

    for (char& c : result) {
        if (std::isalpha(c) && std::islower(c)) {
            c = 'a' + (c - 'a' - shift + 26) % 26;
        }
    }

    return result;
}

void Caesar::write(const std::string& fileName, const std::string& message) {
    Encrypt::write(fileName, message);
}

std::string Caesar::read(const std::string& fileName) {
    return Encrypt::read(fileName);
}
