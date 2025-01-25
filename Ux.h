//
// Created by ZBook Fury on 24/01/2025.
//

#ifndef UX_H
#define UX_H
#include<iostream>
#include <cctype>
#include "GlobalSparset.h"
#include "users.h"
using namespace std;
#include "users.h"
class Ux {
protected:
    users User;
    int id=0;
public:
    bool isValidPassword(const std::string& password);
    void SignUp();
    void SignIn();
    void Menu();
    void AdminMenu();

};




#endif //UX_H
