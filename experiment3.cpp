#include <iostream>
#include <fstream>
using namespace std;

string punctuations[10] = {";", "(", ")", "{", "}", "[", "]", ":", ".", "\""};
string keywords[10] = {"int", "float", "if", "main", "class", "while", "char", "stack", "return", "true"};
string op[10] = {"=", "<", ">", "!", "+", "-", "*", "/", "<<", ">>"};

string totalTokens[1000];
int totalTokenCount = 0;
int lineNumber = 1;
bool inQuotes = false;

bool tokenScanned(string token) {
    for(int i = 0; i < totalTokenCount; i++) {
        if (totalTokens[i] == token) {
            return true;
        }
    }
    return false;
}

bool isConstant(string text) {
    int n = text.length();

    if (n == 0) {
        return false;
    }

    bool numeric = true;
    int dotCount = 0;

    for (int i = 0; i < n; i++) {
        int asciiVal = text[i];

        if (asciiVal == 46) {
            dotCount++;
            if (dotCount > 1) {
                numeric = false;
                break;
            }
        }
        else if (asciiVal < 48 || asciiVal > 57) {
            numeric = false;
            break;
        }
    }

    return numeric;
}

bool isIdentifier(string text) {
    int n = text.length();
    
    if (n == 0) return false;

    for (int i = 0; i < n; i++) {
        int asciiVal = text[i];

        if (!((asciiVal >= 65 && asciiVal <= 90) || (asciiVal >= 97 && asciiVal <= 122))) {
            return false;
        }
    }
    return true;
}

void validateToken(string input, ofstream& outFile) {
    string currTokens[100];
    string currWord = "";
    int currTokenCount = 0;

    for (int i=0; i<input.length(); i++) {
        if(input[i] == ' ') {
            if(currWord.length() > 0) {
                currTokens[currTokenCount] = currWord;
                currTokenCount++;
                currWord = "";
            }
        }
        else {
            currWord += input[i];
        }
    }

    if(currWord.length() > 0) {
        currTokens[currTokenCount] = currWord;
        currTokenCount++;
    }

    if (currTokenCount == 0) {
        return;
    }

    bool lineNumPrinted = false;

    for (int i = 0; i < currTokenCount; i++) {
        if (tokenScanned(currTokens[i])) {
            if (currTokens[i] == "\"") {
                inQuotes = !inQuotes;
            }
            continue;
        }

        string tokenType = "INVALID TOKEN";
        bool matched = false;

        for(int j=0; j < 10; j++) {
            if(currTokens[i] == keywords[j]) {
                tokenType = "Keyword";
                matched = true;
                break;
            }
        }

        if (!matched) {
            for (int j=0; j < 10; j++) {
                if(currTokens[i] == op[j]) {
                    tokenType = "Operator";
                    matched = true;
                    break;
                }
            }
        }

        if (!matched) {
            for (int j = 0; j < 10; j++) {
                if (currTokens[i] == punctuations[j]) {
                    tokenType = "Punctuation";
                    matched = true;
                    if (currTokens[i] == "\"") {
                        inQuotes = !inQuotes;
                    }
                    break;
                }
            }
        }

        if (!matched) {
            if(isConstant(currTokens[i]) || inQuotes) {
                tokenType = "Constant";
                matched = true;
            }
        }

        if (!matched) {
            if (isIdentifier(currTokens[i])) {
                tokenType = "Identifier";
            }
        }

        if (!lineNumPrinted) {
            cout << "Line-" << lineNumber << ":" << endl;
            outFile << "Line-" << lineNumber << ":" << endl;
            lineNumPrinted = true;
        }

        cout << currTokens[i] << " -> " << tokenType << endl;
        outFile << currTokens[i] << " -> " << tokenType << endl;
        
        totalTokens[totalTokenCount++] = currTokens[i];
    }
    
    if (lineNumPrinted) {
        cout << endl;
        outFile << endl;
    }
}

int main() {
    string text;

    ifstream MyReadFile("Question.txt");
    ofstream MyWriteFile("Tokens.txt");
    
    cout << endl;

    while (getline(MyReadFile, text)) {
        validateToken(text, MyWriteFile);
        lineNumber++;
    }

    MyReadFile.close();
    MyWriteFile.close();
    
    return 0;
}
