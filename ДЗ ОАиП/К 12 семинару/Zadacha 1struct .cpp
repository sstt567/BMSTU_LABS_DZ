/*
#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    int age;
    string position;
    double salary;
};

int main() {
    setlocale(LC_ALL, "Ru");

    Employee emp[3];
    double total = 0;

    for (int i = 0; i < 3; i++) {
        cout << "Сотрудник " << i + 1 << ":" << endl;
        cout << "Имя: "<<endl; cin >> emp[i].name;
        cout << "Возраст: " << endl; cin >> emp[i].age;
        cout << "Должность: " << endl; cin >> emp[i].position;
        cout << "Зарплата: " << endl; cin >> emp[i].salary;
        cout << endl;
        total += emp[i].salary;
    }

    int young = 0, old = 0;
    for (int i = 1; i < 3; i++) {
        if (emp[i].age < emp[young].age) young = i;
        if (emp[i].age > emp[old].age) old = i;
    }

    cout << "Самый молодой: " << emp[young].name << " (" << emp[young].age << " лет)" << endl;
    cout << "Самый старший: " << emp[old].name << " (" << emp[old].age << " лет)" << endl;
    cout << "Средняя зарплата: " << total / 3 << endl;

    return 0;
}
*/