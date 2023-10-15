#include <iostream>
#include <algorithm> // Include the <algorithm> header for swap
#include <string>

void pichey(char arr[], int n) { // Change the function signature to accept a char array
    int s = 0;
    int e = n - 1;
    while (s < e) {
        std::swap(arr[s++], arr[e--]); // Use std::swap to avoid conflicts
    }
}

using namespace std;

int main() {
    char s[20];
    cout << "kuch likhdo aab toh: ";
    cin >> s;
    cout << "yahi likha kya bey tum xi: " << endl;
    cout << s;

    pichey(s, strlen(s)); // Pass the character array and its length

    cout << "\nReversed string: " << s;

    return 0;
}
