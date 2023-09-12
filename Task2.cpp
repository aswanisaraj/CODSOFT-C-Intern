
 /*  Develop a calculator program that performs basic arithmetic
operations such as addition, subtraction, multiplication, and
division. Allow the user to input two numbers and choose an
operation to perform. */

#include <iostream>

using namespace std; 

int main() {
    char choice;
    double num1, num2;

    
    cout << "Select operation." << endl;
    cout << "1.Add" << endl;
    cout << "2.Subtract" << endl;
    cout << "3.Multiply" << endl;
    cout << "4.Divide" << endl;

    cout << "Enter choice(1/2/3/4): ";
    cin >> choice;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    switch (choice) {
        case '1':
            cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
            break;
        case '2':
            cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
            break;
        case '3':
            cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
            break;
        case '4':
            if (num2 == 0) {
                cout << "Error: Division by zero" << endl;
            } else {
                cout << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
            }
            break;
        default:
            cout << "Invalid input" << endl;
            break;
    }

    return 0;
}
