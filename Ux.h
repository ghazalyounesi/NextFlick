//
// Created by ZBook Fury on 23/01/2025.
//

#ifndef UX_H
#define UX_H
#include<iostream>
#include <cctype>

#include "users.h"
using namespace std;
#include "users.h"
class Ux {
 users user;
public:
    bool isValidPassword(const std::string& password);
    void SignUp();
    void SignIn();
    void Menu();

};



#endif //UX_H
