//
// Created by ghazal on 1/23/25.
//

#include "users.h"
users::users() {}

void users::addUser(int Id, std::string username, std::string password) {
    arrUsers.push_back(user(Id,username,password));
    //bool usernameFound = false;
}
bool users::ExistUser(string username, string password) {
        for (user& user : arrUsers) {
            if (user.username == username) {
                return true;
            }
            if (user.password == password) {
                return true;
            }
        }
        return false;
    }
