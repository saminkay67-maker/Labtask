
#include <iostream>
#include <string>
using namespace std;

int letterCheck(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int numberCheck(char c) {
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int symbolCheck(char c) {
    if (letterCheck(c) == 0 && numberCheck(c) == 0 && c != ' ' && c != '"')
        return 1;
    return 0;
}

int main() {
    string input = "<< a+b%\"60\"*2.75";
    int n = input.length();

    for (int i = 0; i < n; i++) {
        char ch = input[i];

        if (ch == ' ') {
            continue;
        }

        if (letterCheck(ch) == 1) {
            string word = "";
            while (i < n && (letterCheck(input[i]) == 1 || numberCheck(input[i]) == 1)) {
                word += input[i];
                i++;
            }
            i--;
            cout << "Word: " << word << endl;
        }
        else if (ch == '<' && i + 1 < n && input[i + 1] == '<') {
            cout << "Operator: <<" << endl;
            i++;
        }
        else if (ch == '"') {
            string str = "";
            i++;
            while (i < n && input[i] != '"') {
                str += input[i];
                i++;
            }
            cout << "String: " << str << endl;
        }
        else if (numberCheck(ch) == 1) {
            string number = "";
            while (i < n && (numberCheck(input[i]) == 1 || input[i] == '.')) {
                number += input[i];
                i++;
            }
            i--;
            cout << "Number: " << number << endl;
        }
        else if (symbolCheck(ch) == 1) {
            cout << "Symbol: " << ch << endl;
        }
    }

    return 0;
}
