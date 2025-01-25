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
    vector<pair<int,int>> SortYear();
    vector<pair<float, int>> SortScore();
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
    void merge(std::vector<int>& vec, int left, int mid, int right);
    void mergeSort(std::vector<int>& vec, int left, int right);
    void showFavoriteMovies();
};
#endif //NEXTFLICK_USER_H
