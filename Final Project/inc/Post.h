#ifndef POST_H
#define POST_H

#include <string>

class Post {
private:
    std::string _postId;
    std::string _authorUsername;
    std::string _text;
    std::string _timestamp;
    int _likeCount;
public:
    Post(const std::string& postId, const std::string& authorUsername,
         const std::string& text, const std::string& timestamp, int likeCount);
    ~Post() = default;
    std::string getPostId() const;
    std::string getAuthorUsername() const;
    std::string getText() const;
    std::string getTimestamp() const;
    int getLikeCount() const;
    void setLikeCount(int likeCount);
};

#endif
