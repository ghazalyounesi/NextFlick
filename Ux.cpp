//
// Created by ZBook Fury on 24/01/2025.
//

#include "Ux.h"
#include "users.h"
#include "admin.h"
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

void Ux::SignIn() {
    while (true) {
        string username;
        std::cout<<"Sign In"<<std::endl;
        std::cout<<"Please Enter Your UserName"<<std::endl;
        cin>>username;
        std::cout<<"Please Enter Your Password"<<std::endl;
        string password;
        cin>>password;
        if (user.ExistUser(username , password)) {
            cout<<"log in\n";
            //userpanel
            break;
        }
        if (username == "admin" || password == "admin") {
            cout<<"Admin\n";
            //adminpannel
            admin Admin;
            int cmd;
            while (cmd != 0) {
                AdminMenu();
                cout<<"Enter Command:"<<endl;
                cin >> cmd;
                cout<<endl;
                switch (cmd) {
                    case 1:
                        Admin.addContent();
                    break;
                    /*case 2:

                    break;*/
                }

            }
            break;
        }
        cout<<"Error!!Please try again..."<<std::endl;
    }
}
void Ux::AdminMenu(){
    std::cout << "Menu Options:\n";
    std::cout << "1 - Add\n";
    std::cout << "2 - Delete\n";
    std::cout << "0- Exit\n";
}

void Ux::Menu() {
    std::cout << "Menu Options:\n";
    std::cout << "1 - SignUp\n";
    std::cout << "2 - SignIn\n";
    std::cout << "0- Exit\n";
}
