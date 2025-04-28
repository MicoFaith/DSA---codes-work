#include <iostream>
using namespace std;

int main() {
    // Step 2: Initialize the scores array
    int scores[] = {52, 78, 75, 68, 88, 63, 75, 90, 78};
    int len = 9;  // Length of the scores array
    int item = 10; // Item to insert
    int k = 3; // Position to insert the item
    int j = len - 1; // Starting from the last index of the array

    // Step 4: Repeat steps 5 and 6 while j >= k
    while (j >= k) {
        scores[j + 1] = scores[j]; // Step 5: Move each element to the right
        j--; // Step 6: Decrement j
    }

    // Step 7: Insert the item at position k
    scores[k] = item;

    // Step 8: Iterate and print the array
    for (int i= 0; i<= len; i++) { // len+1 because we added one item
        cout << scores[i] << " "; // Step 9: Print each score
    }

    cout << endl;
    return 0;
}

