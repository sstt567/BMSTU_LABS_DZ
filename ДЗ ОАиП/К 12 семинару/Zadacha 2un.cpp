/*
#include <iostream>
using namespace std;

union Shape {
    struct { double radius; } circle;
    struct { double length, width; } rectangle;
};

int main() {
    setlocale(LC_ALL, "Ru");

    Shape s;
    int choice;

    cout << "1. Круг\n2. Прямоугольник\nВыберите: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Радиус: ";
        cin >> s.circle.radius;
        cout << "Площадь: " << 3.14 * s.circle.radius * s.circle.radius << endl;
    }
    else if (choice == 2) {
        cout << "Длина: ";
        cin >> s.rectangle.length;
        cout << "Ширина: ";
        cin >> s.rectangle.width;
        cout << "Площадь: " << s.rectangle.length * s.rectangle.width << endl;
    }

    return 0;
}
*/