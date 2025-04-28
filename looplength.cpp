#include <iostream>
#include <string>

int calculateStringLength(const std::string &str) {
    int length = 0;
    int i = 0;
    while (str[i] != '\0') {
        ++length;
        ++i;
    }
    return length;
}

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    std::cout << "Length of the string: " << calculateStringLength(str) << "\n";
    return 0;
}

