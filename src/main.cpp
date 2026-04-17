#include <string>
#include <cctype>
#include <set>
#include <iostream>

bool validSvenskRegNr(const std::string& regNr) {

    if (regNr.length() != 7)
        return false;

    if (regNr[3] != ' ')
        return false;

// cpp godtager allerede ikke Æ Ø og Å
    const std::set<char> forbiddenLetters = {
        'I', 'Q', 'V', 'O'
    };


    const std::set<std::string> offensive = {
        "SEX", "SUX", "DUM", "PIK", "FIS"
    };

    for (int i = 0; i < 3; ++i) {
        char c = regNr[i];

        if (!std::isupper(static_cast<unsigned char>(c)))
            return false;

        if (forbiddenLetters.count(c))
            return false;
    }


    for (int i = 4; i < 7; ++i) {
        char c = regNr[i];

        if (!(std::isdigit(static_cast<unsigned char>(c)) ||
              std::isupper(static_cast<unsigned char>(c))))
            return false;

        if (c == 'O')
            return false;
    }

 
    std::string letters = regNr.substr(0, 3);
    if (offensive.count(letters))
        return false;

    return true;
}

int main() {
    std::string plate = "SKG 912";

    if (validSvenskRegNr(plate)) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "Not OK" << std::endl;
    }
}

