#include <iostream>
#include "Series.h"
#include "Film.h"
#include "splayTree.h"
#include "Globals.h"
#include "admin.h"
#include "user.h"
#include "Ux.h"
#include  "CompressedTrie.h"
splayTree GelobalSplayTree;
MediaHashTable HashGenreRating;
CompressedTrie compressedtrie;
int main() {
  int cmd;
    Ux ux;
    while (cmd != 0) {
        ux.Menu();
        cout<<"Enter Command:"<<endl;
        cin >> cmd;
        cout<<endl;
        switch (cmd) {
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

/*int main() {
    users users;
    Film film1("Inception");
    Film film2("Interstellar");
    Film film3("banana");
    Film film4("band");
    Film film5("catalog");


    GelobalSplayTree.insert(&film1);
    GelobalSplayTree.insert(&film2);
    GelobalSplayTree.insert(&film3);
    GelobalSplayTree.insert(&film4);
    GelobalSplayTree.insert(&film5);

    compressedtrie.insert(&film1);
    compressedtrie.insert(&film2);
    compressedtrie.insert(&film3);
    compressedtrie.insert(&film4);
    compressedtrie.insert(&film5);


    auto result = users.advancedSearch("Imferst");


    cout << "Search results for 'Incept':" << endl;
    for (auto val : result) {
        cout << val->getname() << endl;
    }

    return 0;
}*/

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.