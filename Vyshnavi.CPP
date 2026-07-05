#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char op;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    if (op == '+')
        cout << "Result = " << a + b;
    else if (op == '-')
        cout << "Result = " << a - b;
    else if (op == '*')
        cout << "Result = " << a * b;
    else if (op == '/')
        cout << "Result = " << a / b;
    else
        cout << "Invalid Operator";

    return 0;
}