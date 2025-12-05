/*
#include <iostream>
#include <string>
using namespace std;

struct BankAccount {
    int number;
    string name;
    double balance;
};

int main() {
    setlocale(LC_ALL, "Ru");

    BankAccount acc;
    int choice;

    cout << "1. Создать счет\n2. Положить деньги\n3. Снять деньги\n4. Показать счет\n5. Выход" << endl;

    do {
        cout << "\nВыберите: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Номер счета: "; cin >> acc.number;
            cout << "Владелец: "; cin >> acc.name;
            acc.balance = 0;
            cout << "Счет создан!" << endl;
        }
        else if (choice == 2) {
            double sum;
            cout << "Сумма: "; cin >> sum;
            acc.balance += sum;
            cout << "Пополнено!" << endl;
        }
        else if (choice == 3) {
            double sum;
            cout << "Сумма: "; cin >> sum;
            if (sum <= acc.balance) {
                acc.balance -= sum;
                cout << "Снято!" << endl;
            }
            else {
                cout << "Недостаточно средств!" << endl;
            }
        }
        else if (choice == 4) {
            cout << "Номер: " << acc.number << endl;
            cout << "Владелец: " << acc.name << endl;
            cout << "Баланс: " << acc.balance << endl;
        }
    } while (choice != 5);

    return 0;
}
*/