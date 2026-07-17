#ifndef POST_H
#define POST_H

#include <string>

class Post {
public:
    std::string username;
    std::string content;
    std::string timestamp;

    Post();
    Post(std::string uname, std::string text, std::string time);
};

#endif