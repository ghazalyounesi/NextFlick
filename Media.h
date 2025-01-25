//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_MEDIA_H
#define NEXTFLICK_MEDIA_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <cmath>

class Media {
protected:
    int id;
    std::string name;
    int releaseYear;
    std::string country;
    std::string genre;
    std::string language;
    double rating;
    int numberRated=0;
    std::string summary;

public:
    Media(int ID,const std::string& name, int releaseYear, const std::string& country,const std::string& genre, const std::string& language, double rating, const std::string& summary)
            : id(ID), name(name), releaseYear(releaseYear), country(country),genre(genre), language(language), rating(rating), summary(summary) {}
    int getId() const { return id; }
    int getYear() const { return releaseYear; }
    double getrating()const{return rating;}
    std::string getgenre()const{return genre;}
    std::string getname()const{return name;}
    std::string getcountry()const{return country;}
    std::string getlanguage()const{return language;}
    std::string getsummery()const{return summary;}
    double averageRating(double userRating){
        rating=(rating*numberRated)+userRating;
        ++numberRated;
        rating=rating/numberRated;
        rating= round(rating * 10.0) / 10.0;
        return rating;
    }
    virtual ~Media() = default;
    Media(const std::string& name):name(name){} //debug
    virtual void displayDetails() const = 0;
};

#endif //NEXTFLICK_MEDIA_H
