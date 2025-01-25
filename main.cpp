#include <iostream>
#include "Series.h"
#include "Film.h"
#include "splayTree.h"
#include "Globals.h"
#include "admin.h"
#include "user.h"
#include "GlobalSparset.h"
#include "Ux.h"
#include  "CompressedTrie.h"
splayTree GelobalSplayTree;
MediaHashTable HashGenreRating;
const int maxMedia = 100;
Media* sparseSetMedia[maxMedia] = {nullptr};
std::unordered_map<std::string, std::vector<int>> languageHashTable;
std::unordered_map<std::string, std::vector<int>> countryHashTable;
int countSparse=0;
CompressedTrie compressedtrie;

int main() {
    /*
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
    */

    int cm;
    Ux ux;
    while (cm != 0) {
        ux.Menu();
        cout<<"Enter Command:"<<endl;
        cin >> cm;
        cout<<endl;
        switch (cm) {
            case 1:
                ux.SignUp();
            break;
            case 2:
                ux.SignIn();
            break;
        }
    }
    
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.