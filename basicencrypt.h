#pragma once
#include "encrypt.h"

class BasicEncrypt : public Encrypt {
public:
    BasicEncrypt() : Encrypt() {}
    std::string encode(const std::string& plainText);
    std::string decode(const std::string& cipherText);
};
