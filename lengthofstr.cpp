#include <iostream>
using namespace std;

int calculateLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {  // Keep counting until we reach the null terminator
        length++;
    }
    return length;
}

int main() {
    char str[] = "Hello, World!";
    cout << "Length of string: " << calculateLength(str) << endl;
    return 0;
}

