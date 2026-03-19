#include "PostManager.h"
#include "Constants.h"
#include "Exceptions.h"
#include <fstream>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

PostManager::PostManager(ILogger* logger, IUtility* utility) 
    : _logger(logger), _utility(utility) {}

std::string PostManager::buildPostsPath(const std::string& username) const {
    return Path::USERS_DIR + username + Files::POSTS;
}

void PostManager::createPost(const std::string& username, const std::string& text) {
    std::vector<Post> posts = loadUserPosts(username);
    int postIndex = posts.size() + 1;
    std::string postId = username + Separator::UNDERSCORE + std::to_string(postIndex);
    std::string timestamp = _utility->getCurrentDateTime();
    std::ofstream file(buildPostsPath(username), std::ios::app);
    if (!file) throw FileException(Error::FILE_WRITE_FAILED);

    if (postIndex > 1)
        file << Separator::POST << Separator::NEWLINE_CHAR;
    file << PostFields::POST_ID << Separator::FIELD << postId << Separator::NEWLINE_CHAR
         << PostFields::AUTHOR_USERNAME << Separator::FIELD << username  << Separator::NEWLINE_CHAR
         << PostFields::TEXT << Separator::FIELD << text << Separator::NEWLINE_CHAR
         << PostFields::TIMESTAMP << Separator::FIELD << timestamp << Separator::NEWLINE_CHAR
         << PostFields::LIKE_COUNT << Separator::FIELD << 0 << Separator::NEWLINE_CHAR;
    file.close();
}

std::vector<Post> PostManager::loadUserPosts(const std::string& username) {
    std::vector<Post> posts;
    std::ifstream file(buildPostsPath(username));
    if (!file) return posts;
    std::string line;
    std::string postId;
    std::string authorUsername;
    std::string text;
    std::string timestamp;

    int likeCount = 0;
    std::string postIdKey = PostFields::POST_ID + Separator::FIELD;
    std::string authorKey = PostFields::AUTHOR_USERNAME + Separator::FIELD;
    std::string textKey = PostFields::TEXT + Separator::FIELD;
    std::string timestampKey = PostFields::TIMESTAMP + Separator::FIELD;
    std::string likeCountKey = PostFields::LIKE_COUNT + Separator::FIELD;

    while (std::getline(file, line)) {
        if (line == Separator::POST) {
            if (!postId.empty()) {
                posts.push_back(Post(postId, authorUsername, text, timestamp, likeCount));
            }
            postId = authorUsername = text = timestamp = Separator::EMPTY_STRING;
            likeCount = 0;
        }
        else if (line.find(postIdKey) == 0)
            postId = line.substr(postIdKey.length());
        else if (line.find(authorKey) == 0)
            authorUsername = line.substr(authorKey.length());
        else if (line.find(textKey) == 0)
            text = line.substr(textKey.length());
        else if (line.find(timestampKey) == 0)
            timestamp = line.substr(timestampKey.length());
        else if (line.find(likeCountKey) == 0)
            likeCount = std::stoi(line.substr(likeCountKey.length()));
    }

    if (!postId.empty())
        posts.push_back(Post(postId, authorUsername, text, timestamp, likeCount));
    file.close();
    return posts;
}

std::vector<std::string> PostManager::getAllUsernames() {
    std::vector<std::string> usernames;
    if (!fs::exists(Path::USERS_DIR)) return usernames;
    for (const auto& entry : fs::directory_iterator(Path::USERS_DIR))
        if (entry.is_directory())
            usernames.push_back(entry.path().filename().string());
    return usernames;
}

std::vector<Post> PostManager::loadAllPosts() {
    std::vector<Post> allPosts;
    for (const std::string& username : getAllUsernames()) {
        std::vector<Post> userPosts = loadUserPosts(username);
        allPosts.insert(allPosts.end(), userPosts.begin(), userPosts.end());
    }
    std::sort(allPosts.begin(), allPosts.end(), [](const Post& a, const Post& b) {
        return a.getTimestamp() > b.getTimestamp();
    });
    return allPosts;
}


void PostManager::updateLikeCount(const std::string& postAuthor,
                                  const std::string& postId, int newCount) {
    std::vector<Post> posts = loadUserPosts(postAuthor);
    std::ofstream file(buildPostsPath(postAuthor));
    if (!file) throw FileException(Error::FILE_WRITE_FAILED);

    bool first = true;
    for (Post& post : posts) {
        if (!first)
            file << Separator::POST << Separator::NEWLINE_CHAR;

        first = false;
        if (post.getPostId() == postId)
            post.setLikeCount(newCount);

        file << PostFields::POST_ID << Separator::FIELD << post.getPostId() << Separator::NEWLINE_CHAR
             << PostFields::AUTHOR_USERNAME << Separator::FIELD << post.getAuthorUsername() << Separator::NEWLINE_CHAR
             << PostFields::TEXT << Separator::FIELD << post.getText() << Separator::NEWLINE_CHAR
             << PostFields::TIMESTAMP << Separator::FIELD << post.getTimestamp() << Separator::NEWLINE_CHAR
             << PostFields::LIKE_COUNT << Separator::FIELD << post.getLikeCount() << Separator::NEWLINE_CHAR;
    }
    file.close();
}
