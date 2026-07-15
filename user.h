#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    std::string username;
    std::string salt;
    size_t hashedPassword;

    User();
    User(std::string uname, std::string s, size_t hpass);
};

#endif
