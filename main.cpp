#include <iostream>
#include "ux.h"
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

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.