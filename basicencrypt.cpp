#include "basicencrypt.h"

std::string BasicEncrypt::encode(const std::string& plain)
{
    _cipher = plain;
    return _cipher;
}

std::string BasicEncrypt::decode(const std::string& cipher)
{
    _plain = cipher;
    return _plain;
}