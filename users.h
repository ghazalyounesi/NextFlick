//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_USERS_H
#define NEXTFLICK_USERS_H
#include "user.h"
#include <vector>
class users {
protected:
    vector<user> arrUsers;

public:
    users();
    void addUser(int Id, string username,string password);
    bool ExistUser(string username, string password);
};


#endif //NEXTFLICK_USERS_H
