#pragma once
#include <string>

class Encrypt {
public:
    Encrypt() : _cipher(""), _plain("") {}
    std::string cipher() const { return _cipher; }
    std::string plain() const { return _plain; }
    virtual std::string encode(const std::string& plainText);
    virtual std::string decode(const std::string& cipherText);    
protected:
    std::string _cipher;
    std::string _plain;
};
