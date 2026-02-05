#ifndef UTILITY_H
#define UTILITY_H

class Utility {
private:
    Utility();
    static Utility* instance;

public:
    Utility(const Utility&) = delete;
    Utility& operator=(const Utility&) = delete;
    static Utility* getInstance();

    double getValidDouble();
    int getValidPositiveInteger();
    void showMenu();
};

#endif
