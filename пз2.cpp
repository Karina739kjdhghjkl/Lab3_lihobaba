#include <iostream>
#include <string>
using namespace std;

int main() {
    int number;
    do {
        cout << "Please enter a number > 60 or press Enter to exit: ";
        string input;
        getline(cin, input);
        if (input.empty()) {
            cout << "Exiting..." << endl;
            break;
        }
        number = stoi(input);
        if (number <= 60) {
            cout << "The entered number is not > 60. Please try again." << endl;
        }
    } while (number <= 60);
    return 0;
}

