#pragma once
#include "encrypt.h"

class BasicEncrypt : public Encrypt {
public:
    BasicEncrypt() : Encrypt() {}
    std::string encode(const std::string& plain);
    std::string decode(const std::string& cipher);
};
