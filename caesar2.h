#pragma once
#include "encrypt.h"

class Caesar2 : public Encrypt {
private:
    int shift;

public:
    Caesar2(int shift);
    std::string encode(const std::string& plainText) const;
    std::string decode(const std::string& cipherText) const;
    void write(const std::string& fileName, const std::string& message) const;
    std::string read(const std::string& fileName) const;
};