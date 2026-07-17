#include <iostream>
#include "usermanager.h"
#include "postmanager.h"

using namespace std;

int main() {
    UserManager userManager;
    PostManager postManager;
    int choice;
    bool loggedIn = false;
    string currentUser;

    // Login/Register menu
    while (!loggedIn) {
        cout << "\n===== Social Media Platform =====\n";
        cout << "1. Register new account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) {
            userManager.registerUser();
        } else if (choice == 2) {
            loggedIn = userManager.loginUser();
        } else if (choice == 3) {
            cout << "Goodbye!\n";
            return 0;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }

    // We need to know WHO logged in to attach posts to them.
    // For now, let's ask again (temporary solution, we'll improve this later)
    cout << "\nConfirm your username: ";
    cin >> currentUser;

    // Main app menu (after login)
    bool running = true;
    while (running) {
        cout << "\n===== Main Menu (" << currentUser << ") =====\n";
        cout << "1. Create a post\n";
        cout << "2. View all posts\n";
        cout << "3. Logout / Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) {
            postManager.createPost(currentUser);
        } else if (choice == 2) {
            postManager.viewAllPosts();
        } else if (choice == 3) {
            cout << "Goodbye!\n";
            running = false;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}