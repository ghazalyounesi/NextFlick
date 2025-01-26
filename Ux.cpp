//
// Created by ZBook Fury on 24/01/2025.
//

#include "Ux.h"
#include "users.h"


bool Ux::isValidPassword(const std::string& password) {
    //cout<<password.length();
    if (password.length() < 8 || password.length() > 20) {

        std::cout << "Password must be at least 8 characters and at most 20 characters.\n";
        return false;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;

    for (char c : password) {
        if (std::isupper(c)) {
            hasUpper = true;
        } else if (std::islower(c)) {
            hasLower = true;
        } else if (std::isdigit(c)) {
            hasDigit = true;
        }
    }

    if (!hasUpper) {
        std::cout << "Password must contain at least one uppercase letter.\n";
        return false;
    }

    if (!hasLower) {
        std::cout << "Password must contain at least one lowercase letter.\n";
        return false;
    }

    if (!hasDigit) {
        std::cout << "Password must contain at least one digit.\n";
        return false;
    }
    return true;
}
void Ux::SignUp(){
    while (true) {

        string username;
        std::cout<<"Sign Up"<<std::endl;
        std::cout<<"Please Enter Your UserName"<<std::endl;
        cin>>username;
        std::cout<<"Please Enter Your Password"<<std::endl;
        string password;
        cin>>password;
        if (isValidPassword(password)) {
            if (User.ExistUser(username , password)) {
                std::cout<<"Password must be unique"<<std::endl;
            }
            else {
                User.addUser(id,username,password);
                id++;
                break;
            }

        }
        if (username == "admin" || password == "admin") {
            std::cout<<"Error!!"<<std::endl;
        }
    }
}

void Ux::SignIn() {
    int cmd;
    string name;
    string username;
    vector<Media*> media;
    while (true) {
        std::cout<<"Sign In"<<std::endl;
        std::cout<<"Please Enter Your UserName"<<std::endl;
        cin>>username;
        std::cout<<"Please Enter Your Password"<<std::endl;
        string password;
        cin>>password;
        if (username == "admin" && password == "admin") {
            cout<<"Admin\n";
            //adminpannel
            while (cmd != 0) {
                AdminMenu();
                cout<<"Enter Command:"<<endl;
                cin >> cmd;
                cout<<endl;
                switch (cmd) {
                    case 1:
                        Admin.addContent();
                        break;
                    case 2:
                        cout<<"Enter the name movie: ";
                        cin>>name;
                        media=User.advancedSearch(name);
                        Admin.deletemedia(media);
                        break;
                    default:
                        if(cmd!=0){
                            cout<<"Invalid number,try again. \n";
                        }

                }

            }
            break;
        }
        else if (User.ExistUser(username , password)) {
            cout<<"log in\n";
            user u=User.findUser(username,password);
            while (cmd != 0) {
                userMenu();
                cout<<"Enter Command:"<<endl;
                cin >> cmd;
                cout<<endl;
                switch (cmd) {
                    case 1:
                        for(int i=0;i<countSparse;++i){
                            if(sparseSetMedia[i]!= nullptr){
                                cout<<sparseSetMedia[i]->getname()<<"\n";
                                cout<<"   Genre: "<<sparseSetMedia[i]->getgenre()<<"\n";
                                cout<<"   Summery: "<<sparseSetMedia[i]->getsummery()<<"\n";
                                cout<<"   language: "<<sparseSetMedia[i]->getlanguage()<<"\n";
                                cout<<"   country: "<<sparseSetMedia[i]->getcountry()<<"\n";
                                cout<<"   year: "<<sparseSetMedia[i]->getYear()<<"\n";
                            }
                        }
                        break;
                    case 2:

                        break;
                    case 3:
                        u.userInterfaceFilter();
                        break;
                    case 4:
                        break;
                    case 5:
                        u.addFavoriteMovies();
                        break;
                    case 6:
                        u.deleteFromFavoriteMovies();
                        break;
                    case 7:
                        u.showFavoriteMovies();
                        break;
                    case 8:
                        u.recommend();
                        break;
                    case 9:
                        u.privilege();
                        break;
                    case 10:
                        break;
                    default:
                        if(cmd !=0){
                            cout<<"Invalid number,try again. \n";
                        }

                }

            }
          break;
        }else{
            cout<<"Error!!Please try again..."<<std::endl;
        }
    }
}
void Ux::AdminMenu(){
    std::cout << "Menu Options:\n";
    std::cout << "1 - Add\n";
    std::cout << "2 - Delete\n";
    std::cout << "0- Exit\n";
}
void Ux::Menu(){
    std::cout << "Menu Options:\n";
    std::cout << "1 - sign up\n";
    std::cout << "2 - sign in\n";
    std::cout << "0- Exit\n";
}

void Ux::userMenu() {
    std::cout << "Menu Options:\n";
    std::cout << "1 - show all media\n";
    std::cout << "2 - Search\n";
    std::cout << "3 - filter\n";
    std::cout << "4 - advanced Search\n";
    std::cout << "5 - add to favorites list\n";
    std::cout << "6 - delete from favorites list\n";
    std::cout << "7 - show favorites list\n";
    std::cout << "8 - making suggestions\n";
    std::cout << "9 - Rating Movies and series\n";
    std::cout << "10 - Decision Tree\n";
    std::cout << "0- Exit\n";
}
