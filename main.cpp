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
DecisionTree decisionTree;

int main() {
    decisionTree.buildTree();
    Film* a=new Film(0,"ghazal",2000,60,"iran","deram","persion",5.6,"ghggyfyfyfhvshjv");
    Film* b=new Film(1,"negin",2020,60,"iran","deram","persion",7.6,"ghggyfyfyfhvshjv");
    Film* c=new Film(2,"aven",2015,90,"usa","action","english",8.5,"ghggyfyfyfhvshjv");
    Film* d=new Film(3,"hari",2005,60,"england","fantezi","english",7.3,"ghggyfyfyfhvshjv");
    Film* e=new Film(4,"pathari",2006,60,"england","fantezi","english",7.5,"ghggyfyfyfhvshjv");
    Film* f=new Film(5,"haripater",2003,60,"england","fantezi","english",8.3,"ghggyfyfyfhvshjv");
    HashGenreRating.addMedia(a);
    GelobalSplayTree.insert(a->getId());
    sparseSetMedia[a->getId()]=a;
    languageHashTable[a->getlanguage()].push_back(a->getId());
    countryHashTable[a->getcountry()].push_back(a->getId());
    compressedtrie.insert(a);
    decisionTree.insert(0);
    cout << "\nMovie added successfully!" << endl;
    countSparse++;

    HashGenreRating.addMedia(b);
    GelobalSplayTree.insert(b->getId());
    sparseSetMedia[b->getId()]=b;
    languageHashTable[b->getlanguage()].push_back(b->getId());
    countryHashTable[b->getcountry()].push_back(b->getId());
    compressedtrie.insert(b);
    decisionTree.insert(1);
    cout << "\nMovie added successfully!" << endl;
    countSparse++;

    HashGenreRating.addMedia(c);
    GelobalSplayTree.insert(c->getId());
    sparseSetMedia[c->getId()]=c;
    languageHashTable[c->getlanguage()].push_back(c->getId());
    countryHashTable[c->getcountry()].push_back(c->getId());
    compressedtrie.insert(c);
    decisionTree.insert(2);
    cout << "\nMovie added successfully!" << endl;
    countSparse++;

    HashGenreRating.addMedia(d);
    GelobalSplayTree.insert(d->getId());
    sparseSetMedia[d->getId()]=d;
    languageHashTable[d->getlanguage()].push_back(d->getId());
    countryHashTable[d->getcountry()].push_back(d->getId());
    compressedtrie.insert(d);
    decisionTree.insert(3);
    cout << "\nMovie added successfully!" << endl;
    countSparse++;

    HashGenreRating.addMedia(e);
    GelobalSplayTree.insert(e->getId());
    sparseSetMedia[e->getId()]=e;
    languageHashTable[e->getlanguage()].push_back(e->getId());
    countryHashTable[e->getcountry()].push_back(e->getId());
    compressedtrie.insert(e);
    decisionTree.insert(4);
    cout << "\nMovie added successfully!" << endl;
    countSparse++;

    HashGenreRating.addMedia(f);
    GelobalSplayTree.insert(f->getId());
    sparseSetMedia[f->getId()]=f;
    languageHashTable[f->getlanguage()].push_back(f->getId());
    countryHashTable[f->getcountry()].push_back(f->getId());
    compressedtrie.insert(f);
    decisionTree.insert(5);
    cout << "\nMovie added successfully!" << endl;
    countSparse++;



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