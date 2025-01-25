//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_ADMIN_H
#define NEXTFLICK_ADMIN_H
#include <iostream>
#include "Film.h"
#include "Series.h"
#include "Globals.h"
#include "GlobalSparset.h"
using namespace std;

class admin {
protected:
    int id;
    int idMedia=0;
    string username;
    string password;
public:
    admin(int Id, string Username, string Password): id(Id),username(Username),password(Password){}
    double roundrating(double rating)const;
    void addContent();
    void addMovie();
    void addSeries();
};


#endif //NEXTFLICK_ADMIN_H
