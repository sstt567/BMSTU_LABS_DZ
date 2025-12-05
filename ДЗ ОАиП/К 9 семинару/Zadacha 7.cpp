/*
#include <iostream>
#include <memory>
#include <cstring>
#include <vector>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    setlocale(LC_ALL, "RU");

    string input;
    cout << "Введите строку: ";
    cin>>input;

    unique_ptr<char[]> str = make_unique<char[]>(input.length() + 1);
    strcpy(str.get(), input.c_str());

    int vowels = 0, consonants = 0;
    for (int i = 0; i < input.length(); i++) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            if (isVowel(c)) {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    cout << "Гласных: " << vowels << endl;
    cout << "Согласных: " << consonants << endl;

    unique_ptr<char[]> vowelsOnly = make_unique<char[]>(vowels + 1);
    int index = 0;
    for (int i = 0; i < input.length(); i++) {
        if (isVowel(str[i])) {
            vowelsOnly[index++] = str[i];
        }
    }
    vowelsOnly[index] = '\0';

    cout << "Гласные буквы: " << vowelsOnly.get() << endl;

    return 0;
}
*/