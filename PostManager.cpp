#include "PostManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

// Get current date/time as a string
string PostManager::getCurrentTime() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    stringstream ss;
    ss << (1900 + ltm->tm_year) << "-"
       << (1 + ltm->tm_mon) << "-"
       << ltm->tm_mday << " "
       << ltm->tm_hour << ":"
       << ltm->tm_min;

    return ss.str();
}

vector<Post> PostManager::loadPosts() {
    vector<Post> posts;
    ifstream file("posts.txt");

    if (!file.is_open()) {
        return posts;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string uname, content, time;

        getline(ss, uname, '|');
        getline(ss, content, '|');
        getline(ss, time, '|');

        if (!uname.empty()) {
            posts.push_back(Post(uname, content, time));
        }
    }

    file.close();
    return posts;
}

void PostManager::savePost(const Post& post) {
    ofstream file("posts.txt", ios::app);
    file << post.username << "|" << post.content << "|" << post.timestamp << endl;
    file.close();
}

void PostManager::createPost(const string& username) {
    cin.ignore(); // clear leftover newline from previous cin
    string content;

    cout << "\n--- Create a new post ---\n";
    cout << "What's on your mind? ";
    getline(cin, content);

    string time = getCurrentTime();
    Post newPost(username, content, time);
    savePost(newPost);

    cout << "Post published successfully!\n";
}

void PostManager::viewAllPosts() {
    vector<Post> posts = loadPosts();

    if (posts.empty()) {
        cout << "\nNo posts yet. Be the first to post!\n";
        return;
    }

    cout << "\n===== All Posts =====\n";
    for (const auto& p : posts) {
        cout << "\n[" << p.timestamp << "] " << p.username << ":\n";
        cout << p.content << "\n";
        cout << "-------------------\n";
    }
}