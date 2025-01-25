//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_GLOBALS_H
#define NEXTFLICK_GLOBALS_H

#include <iostream>
#include <vector>
#include "splayTree.h"
#include "MediaHashTable.h"
#include "Media.h"


extern splayTree GelobalSplayTree;
extern MediaHashTable HashGenreRating;
extern std::unordered_map<std::string, std::vector<int>> languageHashTable;
extern std::unordered_map<std::string, std::vector<int>> countryHashTable;
#endif //NEXTFLICK_GLOBALS_H
