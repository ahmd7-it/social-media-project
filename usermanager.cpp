#include "UserManager.h"
#include <iostream>
#include <fstream>
#include <functional>
#include <random>
#include <conio.h>

using namespace std;

// Generate a random salt string
string UserManager::generateSalt() {
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, chars.size() - 1);

    string salt;
    for (int i = 0; i < 16; i++) {
        salt += chars[dist(gen)];
    }
    return salt;
}

// Hash the password combined with salt
size_t UserManager::hashPassword(const string& password, const string& salt) {
    hash<string> hasher;
    return hasher(password + salt); // combine password + salt before hashing
}

vector<User> UserManager::loadUsers() {
    vector<User> users;
    ifstream file("users.txt");

    if (!file.is_open()) {
        return users;
    }

    string uname, salt;
    size_t hpass;
    while (file >> uname >> salt >> hpass) {
        users.push_back(User(uname, salt, hpass));
    }

    file.close();
    return users;
}

void UserManager::saveUser(const User& user) {
    ofstream file("users.txt", ios::app);
    file << user.username << " " << user.salt << " " << user.hashedPassword << endl;
    file.close();
}

bool UserManager::usernameExists(const vector<User>& users, const string& uname) {
    for (const auto& u : users) {
        if (u.username == uname) return true;
    }
    return false;
}
string UserManager::getMaskedPassword() {
    string password;
    char ch;

    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}
void UserManager::registerUser() {
    string uname, pass;

    cout << "\n--- Register new account ---\n";
    cout << "Choose a username: ";
    cin >> uname;

    vector<User> users = loadUsers();

    if (usernameExists(users, uname)) {
        cout << "This username already exists! Try another one.\n";
        return;
    }

    cout << "Choose a password: ";
    pass = getMaskedPassword();

    string salt = generateSalt();
    size_t hpass = hashPassword(pass, salt);

    User newUser(uname, salt, hpass);
    saveUser(newUser);

    cout << "Account created successfully! You can log in now.\n";
}

bool UserManager::loginUser() {
    string uname, pass;

    cout << "\n--- Login ---\n";
    cout << "Username: ";
    cin >> uname;
    cout << "Password: ";
    pass = getMaskedPassword();

    vector<User> users = loadUsers();

    for (const auto& u : users) {
        if (u.username == uname) {
            size_t hpass = hashPassword(pass, u.salt);
            if (hpass == u.hashedPassword) {
                cout << "Login successful! Welcome " << uname << " :)\n";
                return true;
            } else {
                cout << "Wrong username or password.\n";
                return false;
            }
        }
    }

    cout << "Wrong username or password.\n";
    return false;
}