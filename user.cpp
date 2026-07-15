#include "User.h"

User::User() {}

User::User(std::string uname, std::string s, size_t hpass) {
    username = uname;
    salt = s;
    hashedPassword = hpass;
}