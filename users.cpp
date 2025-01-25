//
// Created by ghazal on 1/23/25.
//

#include "users.h"
users::users() {}

void users::addUser(int Id, std::string username, std::string password) {
    arrUsers.push_back(user(Id,username,password));
}

bool users::ExistUser(string username, string password) {
    for (user& user : arrUsers) {
        if (user.getUsername() == username) {
            return true;
        }
        if (user.getPassword() == password) {
            return true;
        }
    }
    return false;
}