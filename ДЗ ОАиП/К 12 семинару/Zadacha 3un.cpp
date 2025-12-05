/*
#include <iostream>
using namespace std;

union DateTime {
    struct {
        int year, month, day, hour, minute, second;
    } parts;
};

int main() {
    setlocale(LC_ALL, "Russian");

    DateTime dt;

    cout << "Год: "; cin >> dt.parts.year;
    cout << "Месяц: "; cin >> dt.parts.month;
    cout << "День: "; cin >> dt.parts.day;
    cout << "Час: "; cin >> dt.parts.hour;
    cout << "Минута: "; cin >> dt.parts.minute;
    cout << "Секунда: "; cin >> dt.parts.second;

    cout << "\nДата и время: ";
    cout << dt.parts.year << "-" << dt.parts.month << "-" << dt.parts.day << " ";
    cout << dt.parts.hour << ":" << dt.parts.minute << ":" << dt.parts.second << endl;

    return 0;
}
*/