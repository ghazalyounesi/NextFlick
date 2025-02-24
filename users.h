//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_USERS_H
#define NEXTFLICK_USERS_H
#include "user.h"
#include <vector>
#include "Globals.h"
#include "GlobalSparset.h"
#include "GlobalsHash.h"

class users {
protected:
    vector<user> arrUsers;

public:
    users();
    void addUser(int Id, string username,string password);
    bool ExistUser(string username, string password);
    vector<Media*> advancedSearch(const string& key);
    int levenshteinTwoMatrixRows(const string& str1,const string& str2);
    void deleteMediaFromFlists(string name);
    user findUser(string username, string password);

};


#endif //NEXTFLICK_USERS_H
