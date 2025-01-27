//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_USER_H
#define NEXTFLICK_USER_H
#include <iostream>
#include "Globals.h"
#include "GlobalsHash.h"
#include "GlobalSparset.h"
using namespace std;
class user{
protected:
    int id;
    string username;
    string password;
    vector<int> favoriteMovies;
public:
    user(int Id, string Username, string Password): id(Id),username(Username),password(Password){}
    void recommend();
    void radixSort(vector<pair<int, int>>& data, int maxKey);
    vector<pair<int,int>> SortYear();
    vector<pair<int, int>> SortScore();
    vector<const Media*> filterByGenre(const string& genre);
    vector<const Media*> filterByGenreAndRating(const string& genre, float minRating);
    vector<const Media*> filterByLanguage(const string& language);
    vector<const Media*> filterByCountry(const string& country);
    vector<const Media*> filterByRating(float minRating);
    vector<const Media*> filterByYear(int year);
    vector<const Media*> combineFilters(const vector<vector<const Media*>>& filters);
    void userInterfaceFilter();
    void privilege();
    void addFavoriteMovies();
    void deleteFromFavoriteMovies();
    void deleteFromFavoriteMovies1(string name);
    void merge(std::vector<int>& vec, int left, int mid, int right);
    void mergeSort(std::vector<int>& vec, int left, int right);
    void showFavoriteMovies();
    string getUsername(){return username;}
    string getPassword(){return password;}

};


#endif //NEXTFLICK_USER_H
