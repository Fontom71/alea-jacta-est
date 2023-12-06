#include "caesar2.h"
#include <cctype>

Caesar2::Caesar2(int shift) : shift(shift) {}

std::string Caesar2::encode(const std::string& plainText) const {
    // prends en charge majuscule, minuscule, chiffre, espace, ponctuation
    std::string result = plainText;

    for (char& c : result) {
        if (std::isprint(c)) {
            if (std::isalpha(c)) {
                char base = (std::islower(c)) ? 'a' : 'A';
                c = base + (c - base + shift) % 26;
            } else if (std::isspace(c)) {
                c = '#';
            }
        }
    }

    return result;
}

std::string Caesar2::decode(const std::string& cipherText) const {
    std::string result = cipherText;

    for (char& c : result) {
        if (std::isprint(c)) {
            if (std::isalpha(c)) {
                char base = (std::islower(c)) ? 'a' : 'A';
                c = base + (c - base - shift + 26) % 26;
            } else if (c == '#') {
                c = ' ';
            }
        }
    }

    return result;
}

void Caesar2::write(const std::string& fileName, const std::string& message) const {
    Encrypt::write(fileName, message);
}

std::string Caesar2::read(const std::string& fileName) const {
    return Encrypt::read(fileName);
}