#include <iostream>
#include <string>
using namespace std;

void task1() {
    string input;
    int isNumeric = 1;

    cout << "Enter input: ";
    cin >> input;

    int len = input.length();

    for (int i = 0; i < len; i++) {
        char ch = input[i];

        if (ch >= '0' && ch <= '9') {
        } else {
            isNumeric = 0;
            break;
        }
    }

    if (isNumeric == 1) {
        cout << "Result: numeric constant" << endl;
    } else {
        cout << "Result: not numeric" << endl;
    }
}

void task2() {
    string input;
    int count = 1;

    cout << "Enter expression: ";
    cin >> input;

    int len = input.length();

    for (int i = 0; i < len; i++) {
        char ch = input[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=') {
            cout << "operator" << count << ": " << ch << endl;
            count++;
        }
    }

    if (count == 1) {
        cout << "No operators found" << endl;
    }
}

void task3() {
    string input;

    cout << "Enter input: ";
    cin.ignore();
    getline(cin, input);

    char first = input[0];
    char second = input[1];
    char secondLast = input[input.length() - 2];
    char last = input[input.length() - 1];

    if (first == '/' && second == '/') {
        cout << "Result: Single line comment" << endl;
    } else if (first == '/' && second == '*' && secondLast == '*' && last == '/') {
        cout << "Result: Multi line comment" << endl;
    } else {
        cout << "Result: Not a comment" << endl;
    }
}

void task4() {
    string input;
    int isValid = 1;

    cout << "Enter input: ";
    cin >> input;

    int len = input.length();
    char first = input[0];

    if ((first >= 'A' && first <= 'Z') || (first >= 'a' && first <= 'z') || first == '_') {
    } else {
        isValid = 0;
    }

    if (isValid == 1) {
        for (int i = 1; i < len; i++) {
            char ch = input[i];

            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '_') {
            } else {
                isValid = 0;
                break;
            }
        }
    }

    if (isValid == 1) {
        cout << "Result: Valid Identifier" << endl;
    } else {
        cout << "Result: Not a Valid Identifier" << endl;
    }
}

void task5() {
    int n;
    float sum = 0;
    float avg;

    cout << "How many elements? ";
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++) {
        cout << "Element[" << i + 1 << "]: ";
        cin >> arr[i];
        sum = sum + arr[i];
    }

    avg = sum / n;

    cout << "Average = " << avg << endl;
}

void task6() {
    int n;

    cout << "How many elements? ";
    cin >> n;

    int arr[100];

    for (int i = 0; i < n; i++) {
        cout << "Element[" << i + 1 << "]: ";
        cin >> arr[i];
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max << endl;
}

void task7() {
    string first;
    string last;
    string full;

    cout << "Enter first name: ";
    cin >> first;

    cout << "Enter last name: ";
    cin >> last;

    full = first + " " + last;

    cout << "full name = \"" << full << "\"" << endl;
}

int main() {
    int choice;

    do {
        cout << "\n========== LAB TASK 1 MENU ==========" << endl;
        cout << "1. Numeric Constant Check" << endl;
        cout << "2. Operator Check" << endl;
        cout << "3. Comment Line Check" << endl;
        cout << "4. Identifier Check" << endl;
        cout << "5. Average of Array" << endl;
        cout << "6. Min and Max of Array" << endl;
        cout << "7. String Concatenation" << endl;
        cout << "0. Exit" << endl;
        cout << "======================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 6: task6(); break;
            case 7: task7(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice, try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
