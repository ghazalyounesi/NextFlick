//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_SERIES_H
#define NEXTFLICK_SERIES_H
#include "Media.h"
class Series : public Media {
private:
    int episodeDuration;
    int seasons;
    int episodes;

public:
    Series(const std::string& name, int releaseYear, int episodeDuration, const std::string& country,const std::string& genre, const std::string& language, double rating, const std::string& summary,int seasons, int episodes)
            : Media(name, releaseYear, country, genre, language, rating, summary),
              episodeDuration(episodeDuration), seasons(seasons), episodes(episodes) {}

    void displayDetails() const override {
        std::cout << "Series: " << name << "\n"
                  << "Year: " << releaseYear << "\n"
                  << "Episode Duration: " << episodeDuration << " minutes\n"
                  << "Country: " << country << "\n"
                  << "Genre: " << genre << "\n"
                  << "Language: " << language << "\n"
                  << "Rating: " << rating << "\n"
                  << "Summary: " << summary << "\n"
                  << "Seasons: " << seasons << "\n"
                  << "Episodes: " << episodes << "\n";
    }
};

#endif //NEXTFLICK_SERIES_H
