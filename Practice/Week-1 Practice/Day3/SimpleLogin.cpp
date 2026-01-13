#include<iostream>
#include<string>

int main(){
    std::string username, password, otp;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter OTP: ";
    std::cin >> otp;
    if(username == "admin"){
        if(password == "pass1234"){
            if(otp == "9375"){
                std::cout << "Login successful" << std::endl;
            }
            else{
                std::cout << "Wrong OTP" << std::endl;
            }
        }
        else{
            std::cout << "Wrong password" << std::endl;
        }
    }
    else{
        std::cout << "User not found" << std::endl;
    }
    return 0;
}