/*
#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
    string genre;
};

int main() {
    setlocale(LC_ALL, "Ru");

    Book books[10];
    int count = 0, choice;

    do {
        cout << "\n1. Добавить книгу\n2. Удалить книгу\n3. Найти по автору\n4. Показать все\n5. Выход" << endl;
        cout << "Выберите: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1 && count < 10) {
            cout << "Название: "; getline(cin, books[count].title);
            cout << "Автор: "; getline(cin, books[count].author);
            cout << "Год: "; cin >> books[count].year;
            cin.ignore();
            cout << "Жанр: "; getline(cin, books[count].genre);
            count++;
        }
        else if (choice == 2) {
            string title;
            cout << "Название для удаления: "; getline(cin, title);
            for (int i = 0; i < count; i++) {
                if (books[i].title == title) {
                    for (int j = i; j < count - 1; j++) {
                        books[j] = books[j + 1];
                    }
                    count--;
                    cout << "Удалено!" << endl;
                    break;
                }
            }
        }
        else if (choice == 3) {
            string author;
            cout << "Автор: "; getline(cin, author);
            for (int i = 0; i < count; i++) {
                if (books[i].author == author) {
                    cout << books[i].title << " (" << books[i].year << ")" << endl;
                }
            }
        }
        else if (choice == 4) {
            for (int i = 0; i < count; i++) {
                cout << i + 1 << ". " << books[i].title << " - " << books[i].author << " (" << books[i].year << ")" << endl;
            }
        }
    } while (choice != 5);

    return 0;
}
*/