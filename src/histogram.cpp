#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void print_histogram(const map<char, int> &frequency_map) {
    int max_frequency = 0;
    for (const auto &entry : frequency_map) {
        max_frequency = max(max_frequency, entry.second);
    }

    for (int i = max_frequency; i > 0; --i) {
        for (const auto &entry : frequency_map) {
            if (entry.second >= i) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (const auto &entry : frequency_map) {
        cout << entry.first;
    }
    cout << endl;
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    map<char, int> frequency_map;
    for (char ch : text) {
        if (ch != ' ' && ch != '\n') {
            frequency_map[ch]++;
        }
    }

    print_histogram(frequency_map);

    return 0;
}
