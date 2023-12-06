#pragma once
#include "encrypt.h"

class Caesar : public Encrypt {
private:
    int shift;

public:
    Caesar(int shift);
    std::string encode(const std::string& plainText);
    std::string decode(const std::string& cipherText);
    void write(const std::string& fileName, const std::string& message);
    std::string read(const std::string& fileName);
};