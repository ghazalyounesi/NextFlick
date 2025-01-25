//
// Created by ghazal on 1/23/25.
//

#include "admin.h"
double admin::roundrating(double rating)const{
    return std::round(rating * 10.0) / 10.0;
}
void admin::addContent() {
    cout << "Do you want to add a Movie or a Series? (Enter M for Movie, S for Series): ";
    char choice;
    cin >> choice;

    if (choice == 'M' || choice == 'm') {
        addMovie();
    } else if (choice == 'S' || choice == 's') {
        addSeries();
    } else {
        cout << "Invalid choice. Please try again." << endl;
    }
}

void admin::addMovie() {
    string name, country, genre, language, summary;
    int releaseYear, duration;
    double rating;

    cout << "Enter movie details:" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Release Year: ";
    cin >> releaseYear;
    cout << "Duration (in minutes): ";
    cin >> duration;
    cout << "Country: ";
    cin.ignore();
    getline(cin, country);
    cout << "Genre: ";
    getline(cin, genre);
    cout << "Language: ";
    getline(cin, language);
    cout << "Rating: ";
    cin >> rating;
    cout << "Summary: ";
    cin.ignore();
    getline(cin, summary);
    rating= roundrating(rating);
    Film* movie = new Film(idMedia,name, releaseYear, duration, country, genre, language, rating, summary);
    HashGenreRating.addMedia(movie);
    GelobalSplayTree.insert(movie);
    CompressedTrie.insert(movie);
    cout << "\nMovie added successfully!" << endl;

}

void admin::addSeries() {
    string name, country, genre, language, summary;
    int releaseYear, episodeDuration, seasons, episodes;
    double rating;

    cout << "Enter series details:" << endl;
    cout << "Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Release Year: ";
    cin >> releaseYear;
    cout << "Episode Duration (in minutes): ";
    cin >> episodeDuration;
    cout << "Country: ";
    cin.ignore();
    getline(cin, country);
    cout << "Genre: ";
    getline(cin, genre);
    cout << "Language: ";
    getline(cin, language);
    cout << "Rating: ";
    cin >> rating;
    cout << "Summary: ";
    cin.ignore();
    getline(cin, summary);
    cout << "Number of Seasons: ";
    cin >> seasons;
    cout << "Number of Episodes: ";
    cin >> episodes;
    rating= roundrating(rating);
    Series* series = new Series(idMedia,name, releaseYear, episodeDuration, country, genre, language, rating, summary, seasons, episodes);
    HashGenreRating.addMedia(series);
    GelobalSplayTree.insert(series);
    cout << "\nSeries added successfully!" << endl;
}