#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void concatenate_strings(string str1, string str2) {
    string result = str1 + str2;
    cout << "Concatenated String: " << result << endl;
}

void reverse_string(string str) {
    string reversed = string(str.rbegin(), str.rend());
    cout << "Reversed String: " << reversed << endl;
}

void to_uppercase(string str) {
    for (char &c : str) {
        c = toupper(c);
    }
    cout << "Uppercase String: " << str << endl;
}

void delete_vowels(string str) {
    string result;
    for (char c : str) {
        if (!isVowel(c)) {
            result += c;
        }
    }
    cout << "String without Vowels: " << result << endl;
}

void sort_string(string str) {
    int n = str.length();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    cout << "Sorted String: " << str << endl;
}

int main() {
    concatenate_strings("Hello, ", "World!");
    reverse_string("Hello, World!");
    to_uppercase("Hello, World!");
    delete_vowels("Hello, World!");
    sort_string("Hello, World!");
    return 0;
}
