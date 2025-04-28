#include <iostream>
#include <cmath>  // For using sqrt function
using namespace std;

bool isInteger(double num) {
    return floor(num) == num;
}

int main() {
    int count = 0;  // Count the number of valid pairs

    for (int a = 2; a < 100; ++a) {
        for (int b = a; b < 100; ++b) {  // Start from 'a' to avoid (b, a) duplicates
            double hypotenuse = sqrt(a * a + b * b);
            if (isInteger(hypotenuse) && hypotenuse < 100) {
                cout << "Pair: (" << a << ", " << b << ") with hypotenuse " << hypotenuse << endl;
                ++count;
            }
        }
    }

    cout << "Total number of pairs found: " << count << endl;
    return 0;
}

