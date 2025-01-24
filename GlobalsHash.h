//
// Created by ghazal on 1/24/25.
//

#ifndef NEXTFLICK_GLOBALSHASH_H
#define NEXTFLICK_GLOBALSHASH_H
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include "Media.h"
using MediaList = std::vector<const Media*>;
using RatingArray = std::vector<MediaList>; // Array of 100 lists (one for each rating bucket)
using GenreTable = std::unordered_map<std::string, RatingArray>;
#endif //NEXTFLICK_GLOBALSHASH_H
