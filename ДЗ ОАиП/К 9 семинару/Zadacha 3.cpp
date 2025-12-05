/*
#include <iostream>
#include <memory>

using namespace std;

void fillArray(unique_ptr<int[]>& arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i * i;
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    unique_ptr<int[]> arr = make_unique<int[]>(n);

    fillArray(arr, n);

    cout << "Массив квадратов: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
*/