
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Calculate factorial recursively
// Base case: 0! = 1
// Recursive case: n! = n * (n - 1)!
long long factorial(int n) {
    if (n < 0) {
        return -1;
    }

    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

// Return the nth Fibonacci number recursively
// Base cases: F(0) = 0, F(1) = 1
// Recursive case: F(n) = F(n - 1) + F(n - 2)
long long fibonacci(int n) {
    if (n < 0) {
        return -1;
    }

    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Reverse a string using recursion
// Base case: zero or one character remains
// Recursive case: reverse the rest and append the first character
string reverseString(string text) {
    if (text.length() <= 1) {
        return text;
    }

    return reverseString(text.substr(1)) + text[0];
}

// Recursive binary search on a sorted array
// Base case: target found or search interval becomes empty
// Recursive case: search the appropriate half
int binarySearch(const vector<int>& arr, int target,
                 int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (target < arr[mid]) {
        return binarySearch(arr, target, low, mid - 1);
    }

    return binarySearch(arr, target, mid + 1, high);
}

int main() {
    cout << "QUESTION 2: RECURSION\n\n";

    // Factorial: normal, zero, and one
    cout << "FACTORIAL TESTS\n";
    cout << "Factorial of 5: " << factorial(5) << '\n';
    cout << "Factorial of 0: " << factorial(0) << '\n';
    cout << "Factorial of 1: " << factorial(1) << '\n';

    // Fibonacci: three different sequence lengths
    cout << "\nFIBONACCI TESTS\n";
    int sizes[] = {1, 5, 7};

    for (int n : sizes) {
        cout << "First " << n << " number(s): ";

        for (int i = 0; i < n; i++) {
            cout << fibonacci(i);
            if (i < n - 1) {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    // String reversal: normal, single character, and empty
    cout << "\nSTRING REVERSAL TESTS\n";
    cout << "hello -> " << reverseString("hello") << '\n';
    cout << "A -> " << reverseString("A") << '\n';
    cout << "Empty string -> ["
         << reverseString("") << "]\n";

    // Binary search: found, absent, and empty array
    cout << "\nBINARY SEARCH TESTS\n";
    vector<int> numbers = {10, 20, 30, 40, 50};

    cout << "Search 30: index "
         << binarySearch(numbers, 30, 0,
                         static_cast<int>(numbers.size()) - 1)
         << '\n';

    cout << "Search 25: index "
         << binarySearch(numbers, 25, 0,
                         static_cast<int>(numbers.size()) - 1)
         << '\n';

    vector<int> emptyArray;

    cout << "Search empty array: index "
         << binarySearch(emptyArray, 10, 0,
                         static_cast<int>(emptyArray.size()) - 1)
         << '\n';

    return 0;
}
