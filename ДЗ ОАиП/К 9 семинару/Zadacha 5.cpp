/*
#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int N, M;
    cout << "Введите количество строк (N): ";
    cin >> N;
    cout << "Введите количество столбцов (M): ";
    cin >> M;

    unique_ptr<int[]> arr = make_unique<int[]>(N * M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr[i * M + j] = i * j;
        }
    }

    cout << "\nТаблица произведений индексов:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(4) << arr[i * M + j] << " ";
        }
        cout << endl;
    }

    return 0;
}
*/