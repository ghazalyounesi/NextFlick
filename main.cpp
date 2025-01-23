#include <iostream>
#include "Series.h"
#include "Film.h"
#include "splayTree.h"
#include "Globals.h"
#include "admin.h"

splayTree GelobalSplayTree;
int main() {
    Media* s= new Series(0,"g",200,12,"hh","hgug","ihuih",6.0,"hghg",12,10);
    Media* f=new Film(1,"g",200,12,"hh","hgug","ihuih",6.0,"hghg");
    splayTree tree;
    tree.insert(s);
    tree.insert(f);
    admin* m = new admin(0,"admin","admin");
    m->addContent();

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.