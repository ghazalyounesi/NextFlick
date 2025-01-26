//
// Created by ZBook Fury on 24/01/2025.
//
#ifndef COMPRESSEDTRIE_H
#define COMPRESSEDTRIE_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "Media.h"
using namespace std;

class _Node {
public:
    unordered_map<string, _Node*> children;
    unordered_map<string, Media*> mediaMap;
    bool isEnd;

    _Node() : isEnd(false) {}
};


class CompressedTrie {
private:
    _Node* root;


    string substring(const string& str, int index) {
        return str.substr(index);
    }

    int findCommonPrefix(const string& str1, const string& str2) {
        int i = 0;
        while (i < str1.size() && i < str2.size() && str1[i] == str2[i]) {
            ++i;
        }
        return i;
    }

public:
    // Constructor for the trie
    CompressedTrie() {
        root = new _Node();
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

    _Node* getRoot() {
        return root;
    }
    void insert(Media* film);
    void printTree(_Node* node, const string& prefix);
    vector<Media*> search(const string& query);
    void collectResults(_Node* node, vector<Media*>& results);
    vector<string> getAll();
    void collect(_Node* node, string& currentKey, vector<string>& keys);
    void remove(Media *node);
};

#endif //COMPRESSEDTRIE_H