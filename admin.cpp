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
    GelobalSplayTree.insert(idMedia);
    sparseSetMedia[idMedia]=movie;
    languageHashTable[language].push_back(idMedia);
    countryHashTable[country].push_back(idMedia);
    compressedtrie.insert(movie);
    cout << "\nMovie added successfully!" << endl;
    idMedia++;
    countSparse++;

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
    GelobalSplayTree.insert(idMedia);
    sparseSetMedia[idMedia]=series;
    languageHashTable[language].push_back(idMedia);
    countryHashTable[country].push_back(idMedia);
    compressedtrie.insert(series);
    cout << "\nSeries added successfully!" << endl;
    idMedia++;
    countSparse++;
}

void admin::deletemedia(vector<Media*> media){
    vector<Media*> mediaForDelete= radixSort(media);
    for(int i=0;i<mediaForDelete.size();++i){
        cout<<i+1<<"- "<<mediaForDelete[i]->getname()<<" ("<<mediaForDelete[i]->getYear()<<")\n";
    }
    cout<<" enter the number of movie that you want delete: ";
    int n;
    cin>>n;
    GelobalSplayTree.delete_key(mediaForDelete[n-1]->getId());
    HashGenreRating.removeMediaByName(mediaForDelete[n-1]->getname());
    sparseSetMedia[mediaForDelete[n-1]->getId()]= nullptr;
    compressedtrie.remove(mediaForDelete[n-1]);
    auto langIt = languageHashTable.find(mediaForDelete[n-1]->getlanguage());
    if (langIt != languageHashTable.end()) {
        auto& langVector = langIt->second;
        for (auto it = langVector.begin(); it != langVector.end(); ++it) {
            if (*it == mediaForDelete[n-1]->getId()) {
                langVector.erase(it);
                break;
            }
        }
    }

    auto countryIt = countryHashTable.find(mediaForDelete[n-1]->getcountry());
    if (countryIt != countryHashTable.end()) {
        auto& countryVector = countryIt->second;
        for (auto it = countryVector.begin(); it != countryVector.end(); ++it) {
            if (*it == mediaForDelete[n-1]->getId()) {
                countryVector.erase(it);
                break;
            }
        }
    }

}

void admin::countingSort(vector<Media*>& media, int exp) {
    int n = media.size();
    vector<Media*> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (media[i]->getYear() / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (media[i]->getYear() / exp) % 10;
        output[count[digit] - 1] = media[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        media[i] = output[i];
    }
}

vector<Media*> admin::radixSort(vector<Media*>& media) {
    int maxYear = 0;
    for (Media* m : media) {
        maxYear = max(maxYear, m->getYear());
    }

    for (int exp = 1; maxYear / exp > 0; exp *= 10) {
        countingSort(media, exp);
    }
    return media;
}