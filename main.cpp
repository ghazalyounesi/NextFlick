#include <iostream>
#include "Series.h"
#include "Film.h"
#include "splayTree.h"
#include "Globals.h"
#include "admin.h"
#include "user.h"
#include "GlobalSparset.h"
splayTree GelobalSplayTree;
MediaHashTable HashGenreRating;
const int maxMedia = 100;
Media* sparseSetMedia[maxMedia] = {nullptr};
std::unordered_map<std::string, std::vector<int>> languageHashTable;
std::unordered_map<std::string, std::vector<int>> countryHashTable;
int countSparse=0;
int main() {
    admin a(0,"h","h");
    a.addContent();
    a.addContent();
    a.addContent();
    a.addContent();
    user w(0,"j","j");
    //vector<int> b=w.SortYear();
    w.recommend();
    w.userInterfaceFilter();
    w.userInterfaceFilter();
    w.userInterfaceFilter();

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.