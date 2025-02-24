//
// Created by ghazal on 1/23/25.
//

#include "users.h"

#include <algorithm>
#include <set>
#include <bits/ranges_algo.h>
users::users() {}

void users::addUser(int Id, std::string username, std::string password) {
    arrUsers.push_back(user(Id,username,password));
}

bool users::ExistUser(string username, string password) {
    for (user& user : arrUsers) {
        if (user.getUsername() == username &&user.getPassword() == password ) {
            return true;
        }
    }
    return false;
}
int users::levenshteinTwoMatrixRows(const string& str1,
                            const string& str2)
{
    int m = str1.length();
    int n = str2.length();

    vector<int> prevRow(n + 1, 0);
    vector<int> currRow(n + 1, 0);

    for (int j = 0; j <= n; j++) {
        prevRow[j] = j;
    }

    for (int i = 1; i <= m; i++) {
        currRow[0] = i;

        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                currRow[j] = prevRow[j - 1];
            }
            else {
                currRow[j] = 1
                            + min(

                                // Insert
                                currRow[j - 1],
                                min(

                                    // Remove
                                    prevRow[j],

                                    // Replace
                                    prevRow[j - 1]));
            }
        }

        prevRow = currRow;
    }

    return currRow[n];
}
void merge(vector<pair<Media*, int>>& vec, int left, int mid, int right) {
    vector<pair<Media*, int>> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (vec[i].second <= vec[j].second) {
            temp.push_back(vec[i++]);
        } else {
            temp.push_back(vec[j++]);
        }
    }

    while (i <= mid) temp.push_back(vec[i++]);
    while (j <= right) temp.push_back(vec[j++]);

    for (int k = left; k <= right; k++) {
        vec[k] = temp[k - left];
    }
}


void mergeSort(vector<pair<Media*, int>>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}
vector<Media*> users::advancedSearch(const string& str) {
    vector<Media*> res;
    set<int> seen;

    vector<string> keys = compressedtrie.getAll();
    for (const string& key : keys) {
        if (levenshteinTwoMatrixRows(str, key) <= 2 || str == key) {
            vector<Media*> temp = compressedtrie.search(key);
            for (Media* m : temp) {
                if (seen.find(m->getId()) == seen.end()) {
                    res.push_back(m);
                    seen.insert(m->getId());
                }
            }
        }
    }

    vector<Media*> prefixResults = compressedtrie.search(str);
    for (Media* m : prefixResults) {
        if (seen.find(m->getId()) == seen.end()) {
            res.push_back(m);
            seen.insert(m->getId());
        }
    }
    vector<pair<Media*, int>> vec;
    for (Media* m : res) {
        vec.push_back({m, GelobalSplayTree.depth(m->getId())});
    }

    /*sort(vec.begin(), vec.end(), [](const pair<Media*, int>& a, const pair<Media*, int>& b) {
        return a.second > b.second;
    });*/
    mergeSort(vec, 0, res.size() - 1);
    vector<Media*> sortedRes;
    for (const auto& p : vec) {

            sortedRes.push_back(p.first);

    }
    return sortedRes;
}



user users::findUser(std::string username, std::string password) {
    for (user& user : arrUsers) {
        if (user.getUsername() == username &&user.getPassword() == password ) {
            return user;
        }
    }
}

void users::deleteMediaFromFlists(string name){
    for(int i=0; i<arrUsers.size();++i){
        arrUsers[i].deleteFromFavoriteMovies1(name);
    }
}