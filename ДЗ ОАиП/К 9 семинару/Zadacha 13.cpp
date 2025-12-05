/*
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    unique_ptr<string> part1 = make_unique<string>("Sensor data:");
    unique_ptr<string> part2 = make_unique<string>("Voltage stable.");
    unique_ptr<string> part3 = make_unique<string>("System nominal.");

    vector<unique_ptr<string>> reportParts;
    reportParts.push_back(move(part1));
    reportParts.push_back(move(part2));
    reportParts.push_back(move(part3));

    string fullReport;
    auto concatParts = [&fullReport](vector<unique_ptr<string>>& parts) {
        for (const auto& part : parts) {
            fullReport += *part + "\n";
        }
    };

    concatParts(reportParts);

    auto countWord = [](const string& text, const string& word) -> int {
        int count = 0;
        size_t pos = 0;
        while ((pos = text.find(word, pos)) != string::npos) {
            count++;
            pos += word.length();
        }
        return count;
    };

    int dataCount = countWord(fullReport, "data");

    cout << "Отчёт:\n" << fullReport << endl;
    cout << "Слово \"data\" встречается " << dataCount << " раз" << endl;

    return 0;
}
*/