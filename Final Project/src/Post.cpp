#include "Post.h"

Post::Post(const std::string& postId, const std::string& authorUsername,
           const std::string& text, const std::string& timestamp, int likeCount)
    : _postId(postId), _authorUsername(authorUsername),
      _text(text), _timestamp(timestamp), _likeCount(likeCount) {}

std::string Post::getPostId() const { 
    return _postId; 
}

std::string Post::getAuthorUsername() const { 
    return _authorUsername; 
}

std::string Post::getText() const { 
    return _text; 
}

std::string Post::getTimestamp() const { 
    return _timestamp; 
}

int Post::getLikeCount() const { 
    return _likeCount; 
}

void Post::setLikeCount(int likeCount) { 
    _likeCount = likeCount; 
}
