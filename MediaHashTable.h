//
// Created by ghazal on 1/24/25.
//

#ifndef NEXTFLICK_MEDIAHASHTABLE_H
#define NEXTFLICK_MEDIAHASHTABLE_H
#include "GlobalsHash.h"

class MediaHashTable {
private:


public:
    GenreTable genreTable;

    int ratingIndex(double rating) const;
    MediaHashTable();

    void addMedia(Media* media);
    MediaList findMoviesByGenreAndRating(const std::string& genre, double rating) const;
    void display() const;
    void printTop10MoviesByGenre(const std::string& genre) const;
};



#endif //NEXTFLICK_MEDIAHASHTABLE_H
