#include <iostream>
#include <vector>

using namespace std;

int max_truthful_turtles(int n, const vector<pair<int, int>> &statements) {
    int max_truthful = 0;

    for (int i = 0; i <= n; i++) {
        int truthful_count = 0;

        for (const auto &statement : statements) {
            int ahead = statement.first;
            int behind = statement.second;

            if (ahead <= i && behind <= n - i - 1) {
                truthful_count++;
            }
        }

        max_truthful = max(max_truthful, truthful_count);
    }

    return max_truthful;
}

int main() {
    int n;
    cout << "Enter the number of turtles: ";
    cin >> n;

    vector<pair<int, int>> statements(n);
    cout << "Enter statements (a b) for each turtle:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> statements[i].first >> statements[i].second;
    }

    int result = max_truthful_turtles(n, statements);
    cout << "Maximum number of truthful turtles: " << result << endl;

    return 0;
}

//NEED FIX