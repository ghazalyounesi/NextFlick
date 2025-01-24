#include <iostream>
#include "CompressedTrie.h"
#include "Film.h"
int main() {


    CompressedTrie trie;
    Film* film1 = new Film("Negin");
    Film* film2 = new Film("Negar");
    Film* film3 = new Film("Ali");
    Film* film4 = new Film("Negarin");
    Film* film5 = new Film("Alina");
    Film* film6 = new Film("Anna");
    Film* film7 = new Film("Neg");
    Film* film8 = new Film("Abi");
    Film* film9 = new Film("Nima");

    trie.insert(film1);
    trie.insert(film2);
    trie.insert(film3);
    trie.insert(film4);
    trie.insert(film5);
    trie.insert(film6);
    trie.insert(film7);
    trie.insert(film8);
    trie.insert(film9);

    /*cout << "Search prefix: 'Al'" << endl;
    auto vex = trie.search("A");
    if (vex.empty()) {
        cout << "No matches found for the prefix 'Al'.\n";
    } else {
        for (const auto& v : vex) {
            cout << v->getName() << " ";
        }
        cout << endl;
    }

    cout << "Search prefix: 'Neg'" << endl;
    vex = trie.search("Nim");
    if (vex.empty()) {
        cout << "No matches found for the prefix 'Neg'.\n";
    } else {
        for (const auto& v : vex) {
            cout << v->getName() << " ";
        }
        cout << endl;
    }*/


    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.