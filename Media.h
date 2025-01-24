//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_MEDIA_H
#define NEXTFLICK_MEDIA_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Media {
protected:
    std::string name;
    int releaseYear;
    std::string country;
    std::string genre;
    std::string language;
    double rating;
    std::string summary;

public:
    Media(const std::string& name, int releaseYear, const std::string& country,const std::string& genre, const std::string& language, double rating, const std::string& summary)
            : name(name), releaseYear(releaseYear), country(country),genre(genre), language(language), rating(rating), summary(summary) {}
    Media(const std::string& name):name(name) {}
    virtual ~Media() = default;
    std::string getName() const { return name; }
    virtual void displayDetails() const = 0;
};

#endif //NEXTFLICK_MEDIA_H
