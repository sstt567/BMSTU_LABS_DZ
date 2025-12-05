/*
#include <iostream>
using namespace std;

union Variant {
    int i;
    double d;
    char c;
};

int main() {
    setlocale(LC_ALL, "Ru");

    Variant v;
    char type;

    cout << "Тип (i/d/c): ";
    cin >> type;

    if (type == 'i') {
        cout << "Число: ";
        cin >> v.i;
        cout << "Вы ввели: " << v.i << endl;
    }
    else if (type == 'd') {
        cout << "Число: ";
        cin >> v.d;
        cout << "Вы ввели: " << v.d << endl;
    }
    else if (type == 'c') {
        cout << "Символ: ";
        cin >> v.c;
        cout << "Вы ввели: " << v.c << endl;
    }

    return 0;
}
*/