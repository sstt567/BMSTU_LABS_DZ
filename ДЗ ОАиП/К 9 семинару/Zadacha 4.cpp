/*
#include <iostream>
#include <memory>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    unique_ptr<int> ptr1 = make_unique<int>(42);
    cout << "ptr1 указывает на: " << *ptr1 << endl;

    unique_ptr<int> ptr2 = move(ptr1);

    if (ptr1 == nullptr) {
        cout << "ptr1 теперь nullptr" << endl;
    }

    if (ptr2) {
        cout << "ptr2 указывает на: " << *ptr2 << endl;
    }

    return 0;
}
*/