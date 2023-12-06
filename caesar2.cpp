#include "caesar2.h"
#include <cctype>

Caesar2::Caesar2(int shift) : shift(shift) {}

std::string Caesar2::encode(const std::string& plain) {
    _cipher = plain;

    for (char& c : _cipher) {
        if (std::isprint(c)) {
            if (std::isalpha(c)) {
                char base = (std::islower(c)) ? 'a' : 'A';
                c = base + (c - base + shift) % 26;
            } else if (std::isspace(c)) {
                c = '#';
            }
        }
    }

    return _cipher;
}

std::string Caesar2::decode(const std::string& cipher) {
    _plain = cipher;

    for (char& c : _plain) {
        if (std::isprint(c)) {
            if (std::isalpha(c)) {
                char base = (std::islower(c)) ? 'a' : 'A';
                c = base + (c - base - shift + 26) % 26;
            } else if (c == '#') {
                c = ' ';
            }
        }
    }

    return _plain;
}

void Caesar2::write(const std::string& fileName, const std::string& message) {
    Encrypt::write(fileName, message);
}

std::string Caesar2::read(const std::string& fileName) {
    return Encrypt::read(fileName);
}