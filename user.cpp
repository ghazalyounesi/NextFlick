//
// Created by ghazal on 1/24/25.
//
#include "user.h"

void user::recommend() {
    string MaxGenre= GelobalSplayTree.findMaxGenreWithDepthScore();
    HashGenreRating.printTop10MoviesByGenre(MaxGenre);
}

void user::radixSort(vector<pair<int, int>>& data, int maxKey) {
    int n = data.size();
    vector<pair<int, int>> output(n);
    int exp = 1;
    while (maxKey / exp > 0) {
        vector<int> count(10, 0);

        for (int i = 0; i < n; i++) {
            int digit = (data[i].first / exp) % 10;
            count[digit]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            int digit = (data[i].first / exp) % 10;
            output[count[digit] - 1] = data[i];
            count[digit]--;
        }


        for (int i = 0; i < n; i++) {
            data[i] = output[i];
        }

        exp *= 10;
    }
}


vector<pair<int, int>>user:: SortYear() {
    vector<pair<int, int>> yearData;
    for (int i = 0; i < countSparse; i++) {
        if (sparseSetMedia[i]) {
            yearData.emplace_back(sparseSetMedia[i]->getYear(), sparseSetMedia[i]->getId());
        }
    }

    int maxYear = 0;
    for (const auto& entry : yearData) {
        maxYear = max(maxYear, entry.first);
    }

    radixSort(yearData, maxYear);

    return yearData;
}

vector<pair<int, int>> user::SortScore() {
    vector<pair<int, int>> scoreData;

    for (int i = 0; i < countSparse; i++) {
        if (sparseSetMedia[i]) {
            int score = static_cast<int>(sparseSetMedia[i]->getrating() * 10); // تبدیل به عدد صحیح
            scoreData.emplace_back(score, sparseSetMedia[i]->getId());
        }
    }

    int maxScore = 100;

    radixSort(scoreData, maxScore);

    return scoreData;
}


vector<const Media*> user::filterByGenre(const string& genre) {
    vector<const Media*> result;
    if (HashGenreRating.genreTable.find(genre) != HashGenreRating.genreTable.end()) {
        for (const auto& mediaList : HashGenreRating.genreTable[genre]) {
            result.insert(result.end(), mediaList.begin(), mediaList.end());
        }
    }
    return result;
}

vector<const Media*> user::filterByGenreAndRating(const string& genre, float minRating) {
    vector<const Media*> result;
    if (HashGenreRating.genreTable.find(genre) != HashGenreRating.genreTable.end()) {
        const RatingArray& ratingArray = HashGenreRating.genreTable[genre];
        for (int i = static_cast<int>(minRating * 10); i <= 100; i++) {
            for (const Media* media : ratingArray[i]) {
                result.push_back(media);
            }
        }
    }
    return result;
}

vector<const Media*> user::filterByLanguage(const string& language) {
    vector<const Media*> result;
    for (int id : languageHashTable[language]) {
        if (sparseSetMedia[id] != nullptr) {
            result.push_back(sparseSetMedia[id]);
        }
    }
    return result;
}


vector<const Media*> user::filterByCountry(const string& country) {
    vector<const Media*> result;
    for (int id : countryHashTable[country]) {
        if (sparseSetMedia[id] != nullptr) {
            result.push_back(sparseSetMedia[id]);
        }
    }
    return result;
}

vector<const Media*> user::filterByRating(float minRating) {
    vector<const Media*> result;
    vector<pair<int, int>> ratingVector=SortScore();
    for (const auto& [rating, id] : ratingVector) {
        if (rating < minRating) break;
        if (sparseSetMedia[id] != nullptr) {
            result.push_back(sparseSetMedia[id]);
        }
    }
    return result;
}

vector<const Media*> user::filterByYear(int year) {
    vector<const Media*> result;
    vector<pair<int, int>> yearVector=SortYear();
    for (const auto& [releaseYear, id] : yearVector) {
        if (releaseYear == year && sparseSetMedia[id] != nullptr) {
            result.push_back(sparseSetMedia[id]);
        }
    }
    return result;
}


vector<const Media*> user::combineFilters(const vector<vector<const Media*>>& filters) {
    unordered_map<const Media*, int> countMap;
    for (const auto& filterResult : filters) {
        for (const Media* media : filterResult) {
            countMap[media]++;
        }
    }
    vector<const Media*> result;
    for (const auto& [media, count] : countMap) {
        if (count == filters.size()) {
            result.push_back(media);
        }
    }
    return result;
}


void user::userInterfaceFilter() {
    int filterCount;
    cout << "How many filters do you want to apply? ";
    cin >> filterCount;

    vector<vector<const Media*>> filters;
    for (int i = 0; i < filterCount; i++) {
        cout << "\nSelect filter type:\n1. Genre\n2. Genre and Rating\n3. Language\n4. Country\n5. Rating\n6. Year\nChoice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string genre;
            cout << "Enter genre: ";
            cin >> genre;
            filters.push_back(filterByGenre(genre));
        } else if (choice == 2) {
            string genre;
            float minRating;
            cout << "Enter genre: ";
            cin >> genre;
            cout << "Enter minimum rating: ";
            cin >> minRating;
            filters.push_back(filterByGenreAndRating(genre, minRating));
        } else if (choice == 3) {
            string language;
            cout << "Enter language: ";
            cin >> language;
            filters.push_back(filterByLanguage(language));
        } else if (choice == 4) {
            string country;
            cout << "Enter country: ";
            cin >> country;
            filters.push_back(filterByCountry(country));
        } else if (choice == 5) {
            float minRating;
            cout << "Enter minimum rating: ";
            cin >> minRating;
            filters.push_back(filterByRating(minRating));
        } else if (choice == 6) {
            int year;
            cout << "Enter year: ";
            cin >> year;
            filters.push_back(filterByYear(year));
        } else {
            cout << "Invalid choice. Skipping.\n";
        }
    }

    auto result = combineFilters(filters);
    cout << "\nFiltered Results:\n";
    for (const Media* media : result) {
        cout << media->getname() << " (" << media->getYear() << ") - Rating: " << media->getrating() << " - language: "<<media->getlanguage()<<" - country: "<<media->getcountry()<<"\n";
    }
}

void user::privilege() {
    string name;
    double rating;
    cout<<"Enter name movie : ";
    cin>>name;
    cout<<"Enter the score you give to the movie: ";
    cin>>rating;
    for(int i=0;i<countSparse;++i){
        if(sparseSetMedia[favoriteMovies[i]]&&sparseSetMedia[i]->getname()==name){
            sparseSetMedia[i]->averageRating(rating);
            cout<<"Done successfully. \n";
            return;
        }
    }
    cout<<"movie not found. \n";
    return;
}

void user::addFavoriteMovies() {
    string name;
    cout<<"Enter name movie : ";
    cin>>name;
    cout<<"\n";
    for(int i=0;i<countSparse;++i){
        if(sparseSetMedia[favoriteMovies[i]]&&sparseSetMedia[i]->getname()==name){
            favoriteMovies.push_back(i);
            cout<<"Done successfully. \n";
            return;
        }
    }
    cout<<"movie not found. \n";
    return;
}

void user::deleteFromFavoriteMovies() {
    string name;
    cout<<"Enter name movie : ";
    cin>>name;
    cout<<"\n";
    for(int i=0;i<favoriteMovies.size();++i){
        if(sparseSetMedia[favoriteMovies[i]]&&sparseSetMedia[favoriteMovies[i]]->getname()==name){
            favoriteMovies.erase(favoriteMovies.begin() + i);
            cout << "Movie removed successfully.\n";
            return;
        }
    }
    cout<<"movie not found. \n";
    return;
}

void user::merge(std::vector<int>& vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = vec[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = vec[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (sparseSetMedia[L[i]]->getname() <= sparseSetMedia[R[j]]->getname()) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void user::mergeSort(std::vector<int>& vec, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(vec, left, mid);
    mergeSort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

void user::showFavoriteMovies() {
    mergeSort(favoriteMovies, 0, favoriteMovies.size() - 1);
    for(int i=0;i<favoriteMovies.size();++i){
        if(sparseSetMedia[favoriteMovies[i]]){
            cout<<sparseSetMedia[favoriteMovies[i]]->getname()<<" ("<<sparseSetMedia[favoriteMovies[i]]->getYear()<<") score: "<<sparseSetMedia[favoriteMovies[i]]->getrating()<<"\n";

        }
    }
}

