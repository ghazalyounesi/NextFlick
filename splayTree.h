//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_SPLAYTREE_H
#define NEXTFLICK_SPLAYTREE_H
#include "Media.h"
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include "GlobalSparset.h"
struct Node {
    //Media* media;
    int key;
    Node *left, *right;
};
class splayTree {
    protected:
        Node* root;
    public:
        splayTree () : root(nullptr) {}
        Node* newNode( int Id);
        Node* rightRotate(Node* x);
        Node* leftRotate(Node* x);
        Node* splay(Node* root, int key);
        void insert(int Id);
        Media* find(int key);
        std::string findMaxGenreWithDepthScore();
};


#endif //NEXTFLICK_SPLAYTREE_H
