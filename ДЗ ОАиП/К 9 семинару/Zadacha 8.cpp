/*
#include <iostream>
#include <memory>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    const int SIZE = 5;

    unique_ptr<double[]> temperature = make_unique<double[]>(SIZE);
    unique_ptr<double[]> pressure = make_unique<double[]>(SIZE);
    unique_ptr<double[]> humidity = make_unique<double[]>(SIZE);

    double tempValues[] = {20.5, 21.3, 22.1, 19.8, 20.9};
    double pressValues[] = {1013.2, 1012.8, 1013.5, 1012.9, 1013.1};
    double humidValues[] = {65.0, 68.2, 70.1, 63.5, 66.8};

    for (int i = 0; i < SIZE; i++) {
        temperature[i] = tempValues[i];
        pressure[i] = pressValues[i];
        humidity[i] = humidValues[i];
    }

    double tempSum = 0, pressSum = 0, humidSum = 0;
    for (int i = 0; i < SIZE; i++) {
        tempSum += temperature[i];
        pressSum += pressure[i];
        humidSum += humidity[i];
    }

    cout << fixed << setprecision(2);
    cout << "| Параметр     | Среднее значение |" << endl;
    cout << "|--------------|------------------|" << endl;
    cout << "| Температура  | " << setw(10) << tempSum / SIZE << "       |" << endl;
    cout << "| Давление     | " << setw(10) << pressSum / SIZE << "       |" << endl;
    cout << "| Влажность    | " << setw(10) << humidSum / SIZE << "       |" << endl;

    return 0;
}
*/