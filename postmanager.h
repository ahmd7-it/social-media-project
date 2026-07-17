#ifndef POST_MANAGER_H
#define POST_MANAGER_H

#include "Post.h"
#include <vector>
#include <string>

class PostManager {
public:
    std::vector<Post> loadPosts();
    void savePost(const Post& post);
    std::string getCurrentTime();

    void createPost(const std::string& username);
    void viewAllPosts();
};

#endif