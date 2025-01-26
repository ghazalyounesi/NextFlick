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
#include "admin.h"
class Ux {
protected:
    users User;
    admin Admin;
    int id=0;
public:
    bool isValidPassword(const std::string& password);
    void SignUp();
    void SignIn();
    void Menu();
    void AdminMenu();
    void userMenu();

};




#endif //UX_H
