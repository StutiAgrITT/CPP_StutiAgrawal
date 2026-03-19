#ifndef PROFILE_H
#define PROFILE_H

#include <string>

class Profile {
private:
    std::string _username;
    std::string _displayName;
    std::string _bio;
    int _postCount;
public:
    Profile(const std::string& username, const std::string& displayName,
            const std::string& bio, int postCount);
    ~Profile() = default;
    std::string getUsername() const;
    std::string getDisplayName() const;
    std::string getBio() const;
    int getPostCount() const;
    void setUsername(const std::string& username);
    void setDisplayName(const std::string& displayName);
    void setBio(const std::string& bio);
    void setPostCount(int postCount);
};

#endif
