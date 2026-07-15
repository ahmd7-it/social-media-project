#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include "User.h"
#include <vector>
#include <string>

class UserManager {
public:
    std::vector<User> loadUsers();
    std::string getMaskedPassword();
    void saveUser(const User& user);
    bool usernameExists(const std::vector<User>& users, const std::string& uname);
    size_t hashPassword(const std::string& password, const std::string& salt);
    std::string generateSalt();

    void registerUser();
    bool loginUser();
};

#endif