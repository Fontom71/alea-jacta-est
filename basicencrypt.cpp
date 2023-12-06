#include "basicencrypt.h"

std::string BasicEncrypt::encode(const std::string &plainText)
{
    _cipher = plainText;
    return _cipher;
}

std::string BasicEncrypt::decode(const std::string &cipherText)
{
    _plain = cipherText;
    return _plain;
}