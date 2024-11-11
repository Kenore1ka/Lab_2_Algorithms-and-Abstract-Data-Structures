#include <iostream>
#include <string>

using namespace std;

string int_to_roman(int num) {
    const pair<int, string> roman_numerals[] = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                                                {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
                                                {5, "V"},    {4, "IV"},   {1, "I"}};

    string result;
    for (const auto &entry : roman_numerals) {
        while (num >= entry.first) {
            result += entry.second;
            num -= entry.first;
        }
    }
    return result;
}

int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    if (number < 1 || number > 3999) {
        cout << "Number out of range (1-3999)" << endl;
        return 1;
    }

    string roman = int_to_roman(number);
    cout << "Roman numeral: " << roman << endl;

    return 0;
}
