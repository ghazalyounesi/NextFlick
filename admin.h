//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_ADMIN_H
#define NEXTFLICK_ADMIN_H
#include <iostream>
using namespace std;

class admin {
protected:
    int id;
    string username;
    string password;
public:
    admin(int Id, string Username, string Password): id(Id),username(Username),password(Password){}
};


#endif //NEXTFLICK_ADMIN_H
