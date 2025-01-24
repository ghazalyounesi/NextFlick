//
// Created by ZBook Fury on 23/01/2025.
//

#ifndef COMPRESSEDTRIE_H
#define COMPRESSEDTRIE_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Media.h"
using namespace std;

class Node {
public:
    unordered_map<string, Node*> children;
    unordered_map<string, Media*> mediaMap;
    bool isEnd;

    Node() : isEnd(false) {}
};


class CompressedTrie {
private:
    Node* root;


    string substring(const string& str, int index) {
        return str.substr(index);
    }

    int findCommonPrefix(const string& str1, const string& str2);

public:
    // Constructor for the trie
    CompressedTrie() {
        root = new Node();
    }

   /* ~CompressedTrie() {
        deleteTree(root);
    }*/

    /*void deleteTree(Node* node) {
        if (!node) return;
        for (auto& child : node->children) {
            deleteTree(child.second);
        }
        delete node;
    }*/

    Node* getRoot() {
        return root;
    }
    void insert(Media* film);
    void printTree(Node* node, const string& prefix);
    vector<Media*> search(const string& query);
    void collectResults(Node* node, vector<Media*>& results);

};

#endif //COMPRESSEDTRIE_H
