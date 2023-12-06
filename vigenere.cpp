// vigenere.cpp
#include "vigenere.h"
#include <cctype>

Vigenere::Vigenere(const std::vector<int>& key) : key(key) {}

Vigenere::Vigenere(const std::string& keyString) {
    for (char c : keyString) {
        if (std::isalpha(c)) {
            key.push_back(std::tolower(c) - 'a');
        }
    }
}

std::string Vigenere::encode(const std::string& plainText) const {
    std::string result = plainText;
    size_t keyIndex = 0;

    for (char& c : result) {
        if (std::isalpha(c)) {
            char base = (std::islower(c)) ? 'a' : 'A';
            c = base + (c - base + key[keyIndex]) % 26;
            keyIndex = (keyIndex + 1) % key.size();
        }
    }

    return result;
}

std::string Vigenere::decode(const std::string& cipherText) const {
    std::string result = cipherText;
    size_t keyIndex = 0;

    for (char& c : result) {
        if (std::isalpha(c)) {
            char base = (std::islower(c)) ? 'a' : 'A';
            c = base + (c - base - key[keyIndex] + 26) % 26;
            keyIndex = (keyIndex + 1) % key.size();
        }
    }

    return result;
}
