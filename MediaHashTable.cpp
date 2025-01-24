//
// Created by ghazal on 1/24/25.
//

#include "MediaHashTable.h"
MediaHashTable::MediaHashTable() {
    for (auto& genrePair : genreTable) {
        genrePair.second.resize(101);
    }
}

int MediaHashTable::ratingIndex(double rating) const {
    return std::round(rating * 10.0);
}

void MediaHashTable::addMedia(Media* media) {
    double rating = media->getrating();
    int index = ratingIndex(rating);

    if (genreTable[media->getgenre()].empty()) {
        genreTable[media->getgenre()].resize(101); // Initialize array if not done yet
    }

    genreTable[media->getgenre()][index].push_back(media);
}

MediaList MediaHashTable::findMoviesByGenreAndRating(const std::string& genre, double rating) const {
    MediaList result;
    auto genreIt = genreTable.find(genre);
    if (genreIt == genreTable.end()) {
        return result; // Genre not found
    }

    int index = ratingIndex(rating);
    if (index >= 0 && index < 100) {
        result = genreIt->second[index]; // Return the list of movies for the specific rating
    }

    return result;
}

void MediaHashTable::display() const {
    for (const auto& genrePair : genreTable) {
        std::cout << "Genre: " << genrePair.first << "\n";
        const RatingArray& ratings = genrePair.second;
        for (int i = 100; i >= 0; --i) {
            if (!ratings[i].empty()) {
                double rating = i / 10.0;
                rating=round(rating*10)/10.0;
                std::cout << "  Rating: " << rating << "\n";
                for (const Media* media : ratings[i]) {
                    std::cout << "    - " << media->getname() << " (ID: " << media->getId()
                              << ", Rating: " << media->getrating() << ")\n";
                }
            }
        }
    }
}

void MediaHashTable::printTop10MoviesByGenre(const std::string& genre) const {
    auto genreIt = genreTable.find(genre);
    if (genreIt == genreTable.end()) {
        std::cout << "Genre not found: " << genre << "\n";
        return;
    }

    const RatingArray& ratings = genreIt->second;
    MediaList topMovies;

    // Iterate from rating 100 down to 0, collecting movies until topMovies has 10
    for (int i = 100; i >= 0 && topMovies.size() < 10; --i) {
        for (const Media* media : ratings[i]) {
            topMovies.push_back(media);
            if (topMovies.size() == 10) {
                break;
            }
        }
    }

    // Print the top 10 movies
    std::cout << "Top 10 Movies in Genre " << genre <<" are suggested to you "<< "\n";
    for (size_t i = 0; i < topMovies.size(); ++i) {
        const Media* media = topMovies[i];
        std::cout << i + 1 << ". " << media->getname() << " (ID: " << media->getId()
                  << ", Rating: " << media->getrating() << ")\n";
    }
}
