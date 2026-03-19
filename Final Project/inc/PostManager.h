#ifndef POST_MANAGER_H
#define POST_MANAGER_H

#include "ILogger.h"
#include "IUtility.h"
#include "Post.h"
#include <string>
#include <vector>

class PostManager {
private:
    ILogger* _logger;
    IUtility* _utility;
    std::string buildPostsPath(const std::string& username) const;
    std::string generateTimestamp() const;
public:
    PostManager(ILogger* logger, IUtility* utility);
    ~PostManager() = default;
    void createPost(const std::string& username, const std::string& text);
    std::vector<Post> loadUserPosts(const std::string& username);
    std::vector<Post> loadAllPosts();
    std::vector<std::string> getAllUsernames();
    void updateLikeCount(const std::string& postAuthor,
                         const std::string& postId, int newCount);
};

#endif
