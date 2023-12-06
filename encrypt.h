#pragma once
#include <string>

class Encrypt {
public:
    std::string cipher() const { return _cipher; }
    std::string plain() const { return _plain; }
    virtual std::string encode(const std::string& plain);
    virtual std::string decode(const std::string& cipher);  
    virtual void write(const std::string& fileName, const std::string& data);
    virtual std::string read(const std::string& fileName);  
protected:
    std::string _cipher;
    std::string _plain;
};
