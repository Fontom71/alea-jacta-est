// vigenere.h
#pragma once
#include "encrypt.h"
#include <vector>
#include <string>

class Vigenere : public Encrypt {
private:
    std::vector<int> key;

public:
    Vigenere(const std::vector<int>& key);
    Vigenere(const std::string& keyString);
    std::string encode(const std::string& plain);
    std::string decode(const std::string& cipher);
};
