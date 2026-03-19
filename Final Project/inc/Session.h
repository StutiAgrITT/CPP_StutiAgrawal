#ifndef SESSION_H
#define SESSION_H

#include <string>

class Session {
private:
    std::string _currentUsername;
    bool _isLoggedIn;
public:
    Session();
    ~Session() = default;
    void login(const std::string& username);
    void logout();
    std::string getUsername() const;
    bool isLoggedIn() const;
};

#endif
