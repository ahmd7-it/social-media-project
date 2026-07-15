#include <iostream>
#include "usermanager.h"

using namespace std;

int main() {
    UserManager manager;
    int choice;
    bool loggedIn = false;

    while (!loggedIn) {
        cout << "\n===== Social Media Platform =====\n";
        cout << "1. Register new account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) {
            manager.registerUser();
        } else if (choice == 2) {
            loggedIn = manager.loginUser();
        } else if (choice == 3) {
            cout << "Goodbye!\n";
            return 0;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }

    cout << "\n[Next: posts, friends, etc...]\n";

    return 0;
}