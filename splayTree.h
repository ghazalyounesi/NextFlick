//
// Created by ghazal on 1/23/25.
//

#ifndef NEXTFLICK_SPLAYTREE_H
#define NEXTFLICK_SPLAYTREE_H
#include "Media.h"
struct Node {
    Media* media;
    int key;
    Node *left, *right;
};
class splayTree {
    protected:
        Node* root;
    public:
        splayTree () : root(nullptr) {}
        Node* newNode( Media* media);
        Node* rightRotate(Node* x);
        Node* leftRotate(Node* x);
        Node* splay(Node* root, int key);
        void insert(Media* media);
};


#endif //NEXTFLICK_SPLAYTREE_H
