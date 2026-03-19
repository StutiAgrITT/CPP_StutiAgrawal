#include "Profile.h"

Profile::Profile(const std::string& username, const std::string& displayName,
                 const std::string& bio, int postCount)
    : _username(username), _displayName(displayName),
      _bio(bio), _postCount(postCount) {}

std::string Profile::getUsername() const { 
    return _username;
}

std::string Profile::getDisplayName() const { 
    return _displayName; 
}

std::string Profile::getBio() const { 
    return _bio; 
}

int Profile::getPostCount() const { 
    return _postCount; 
}

void Profile::setUsername(const std::string& username) { 
    _username = username; 
}

void Profile::setDisplayName(const std::string& displayName) { 
    _displayName = displayName; 
}

void Profile::setBio(const std::string& bio) { 
    _bio = bio; 
}

void Profile::setPostCount(int postCount) { 
    _postCount = postCount; 
}
