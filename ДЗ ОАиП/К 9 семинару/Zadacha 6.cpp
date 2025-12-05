/*
#include <iostream>
#include <memory>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    shared_ptr<int> ptr1 = make_shared<int>(100);
    cout << "Создан ptr1. use_count: " << ptr1.use_count() << endl;

    shared_ptr<int> ptr2 = ptr1;
    cout << "Создана копия ptr2. use_count: " << ptr1.use_count() << endl;

    shared_ptr<int> ptr3 = ptr1;
    cout << "Создана копия ptr3. use_count: " << ptr1.use_count() << endl;

    {
        shared_ptr<int> ptr4 = ptr1;
        cout << "Внутри блока создан ptr4. use_count: " << ptr1.use_count() << endl;
    }

    cout << "После выхода из блока. use_count: " << ptr1.use_count() << endl;

    return 0;
}
*/