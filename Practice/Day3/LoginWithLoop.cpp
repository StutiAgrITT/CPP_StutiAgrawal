#include<iostream>

int main(){
    std::string username, password;
    std::string expectedUsername, expectedPassword;
    expectedUsername = "admin";
    expectedPassword = "pass1234";

    int attempts = 3;

    while(attempts){
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        
        if(username == expectedUsername && password == expectedPassword){
            std::cout << "Login successful" << std::endl;
            break;
        }
        else{
            attempts--;
            std::cout << "Invalid username or password. Try again." << std::endl;
            std::cout << "Attempts left: " << attempts << std::endl;
        }
    }

    if(!attempts){
        std::cout << "Account blocked." << std::endl;
    }
    return 0;
}