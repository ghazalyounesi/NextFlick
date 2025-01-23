//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_USER_H
#define NEXTFLICK_USER_H
#include <iostream>
using namespace std;
class user{
/*protected:
    int id;
    string username;
    string password;*/
public:
    int id;
    string username;
    string password;
    user(int Id, string Username, string Password): id(Id),username(Username),password(Password){}
};
#endif //NEXTFLICK_USER_H
