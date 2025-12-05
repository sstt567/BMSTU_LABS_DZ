/*
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int N;
    cout << "Введите количество измерений: ";
    cin >> N;

    vector<double> signals(N);
    cout << "Введите " << N << " значений сигналов: ";
    for (int i = 0; i < N; i++) {
        cin >> signals[i];
    }

    unique_ptr<double[]> signalsPtr = make_unique<double[]>(N);
    copy(signals.begin(), signals.end(), signalsPtr.get());

    auto mean = [](unique_ptr<double[]>& arr, int size) -> double {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum / size;
    };

    auto normalize = [](unique_ptr<double[]>& arr, int size, double maxVal) {
        for (int i = 0; i < size; i++) {
            arr[i] /= maxVal;
        }
    };

    auto copyBack = [](unique_ptr<double[]>& arr, vector<double>& vec, int size) {
        for (int i = 0; i < size; i++) {
            vec[i] = arr[i];
        }
    };

    double avg = mean(signalsPtr, N);
    cout << "Среднее значение: " << avg << endl;

    double maxVal = *max_element(signals.begin(), signals.end());

    normalize(signalsPtr, N, maxVal);

    copyBack(signalsPtr, signals, N);

    cout << "Нормализованные сигналы: ";
    for (double val : signals) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
*/