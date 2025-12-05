/*
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    vector<string> logs = {
        "INFO: Start",
        "ERROR: Disk failure",
        "WARNING: Low memory",
        "ERROR: Disk failure",
        "INFO: Stop"
    };

    shared_ptr<vector<string>> logPtr = make_shared<vector<string>>(logs);

    cout << "Исходный журнал:\n";
    for (const auto& log : *logPtr) {
        cout << log << endl;
    }
    cout << endl;

    vector<string> errors;
    copy_if(logPtr->begin(), logPtr->end(), back_inserter(errors),
        [](const string& s) { return s.find("ERROR") != string::npos; });

    sort(errors.begin(), errors.end());
    errors.erase(unique(errors.begin(), errors.end()), errors.end());

    cout << "Ошибки:\n";
    for (const auto& error : errors) {
        cout << error << endl;
    }

    return 0;
}
*/