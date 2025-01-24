//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_FILM_H
#define NEXTFLICK_FILM_H

#include "Media.h"
class Film : public Media {
private:
    int duration{};

public:
    Film(const std::string& name, int releaseYear, int duration, const std::string& country,
         const std::string& genre, const std::string& language, double rating, const std::string& summary)
            : Media(name, releaseYear, country, genre, language, rating, summary), duration(duration) {}
    Film(const std::string &name) : Media(name) {}
    void displayDetails() const override {
        std::cout << "Film: " << name << "\n"
                  << "Year: " << releaseYear << "\n"
                  << "Duration: " << duration << " minutes\n"
                  << "Country: " << country << "\n"
                  << "Genre: " << genre << "\n"
                  << "Language: " << language << "\n"
                  << "Rating: " << rating << "\n"
                  << "Summary: " << summary << "\n";
    }

};
#endif //NEXTFLICK_FILM_H
