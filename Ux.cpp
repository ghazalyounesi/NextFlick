//
// Created by ZBook Fury on 23/01/2025.
//

#include "Ux.h"
bool Ux::isValidPassword(const std::string& password) {
    //cout<<password.length();
    if (password.length() < 8 || password.length() > 20) {

        std::cout << "Password must be at least 8 characters and at most 20 characters.\n";
        return false;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;

    for (char c : password) {
        if (std::isupper(c)) {
            hasUpper = true;
        } else if (std::islower(c)) {
            hasLower = true;
        } else if (std::isdigit(c)) {
            hasDigit = true;
        }
    }

    if (!hasUpper) {
        std::cout << "Password must contain at least one uppercase letter.\n";
        return false;
    }

    if (!hasLower) {
        std::cout << "Password must contain at least one lowercase letter.\n";
        return false;
    }

    if (!hasDigit) {
        std::cout << "Password must contain at least one digit.\n";
        return false;
    }
    return true;
}
void Ux::SignUp(){
    while (true) {
        static int id;
        string username;
        std::cout<<"Sign Up"<<std::endl;
        std::cout<<"Please Enter Your UserName"<<std::endl;
        cin>>username;
        std::cout<<"Please Enter Your Password"<<std::endl;
        string password;
        cin>>password;
        if (isValidPassword(password)) {
                if (user.ExistUser(username , password)) {
                    std::cout<<"Password must be unique"<<std::endl;
                }
            else {
                user.addUser(id,username,password);
                id++;
                break;
            }

        }
        if (username == "admin" || password == "admin") {
            std::cout<<"Error!!"<<std::endl;
        }
    }
}