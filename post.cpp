#include "post.h"

Post::Post() {}

Post::Post(std::string uname, std::string text, std::string time) {
    username = uname;
    content = text;
    timestamp = time;
}