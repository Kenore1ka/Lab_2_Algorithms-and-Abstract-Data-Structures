#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

int evaluate_postfix(const string &expression) {
    stack<int> s;
    stringstream ss(expression);
    char token;

    while (ss >> token) {
        if (isdigit(token)) {
            s.push(token - '0');  // Преобразуем символ в число и помещаем в стек
        } else {
            int right_operand = s.top();
            s.pop();
            int left_operand = s.top();
            s.pop();

            switch (token) {
                case '+':
                    s.push(left_operand + right_operand);
                    break;
                case '-':
                    s.push(left_operand - right_operand);
                    break;
                case '*':
                    s.push(left_operand * right_operand);
                    break;
                case '/':
                    s.push(left_operand / right_operand);
                    break;
                default:
                    cerr << "Invalid operator: " << token << endl;
                    return 0;
            }
        }
    }
    return s.top();
}

int main() {
    string expression;
    cout << "Enter postfix expression: ";
    cin >> expression;

    int result = evaluate_postfix(expression);
    cout << "Result: " << result << endl;

    return 0;
}
