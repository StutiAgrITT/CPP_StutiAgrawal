#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string _username;
    std::string _password;
    std::string _displayName;
    std::string _bio;
public:
    User(const std::string& username, const std::string& password, const std::string& displayName, const std::string& bio);
    ~User() = default;
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getDisplayName() const;
    std::string getBio() const;
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setDisplayName(const std::string& displayName);
    void setBio(const std::string& bio);
};

#endif
