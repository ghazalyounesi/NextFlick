//
// Created by ZBook Fury on 24/01/2025.
//

#include "CompressedTrie.h"

void CompressedTrie::insert(Media *film) {
    Node* current = root;
        string remainingKey = film->getname();

        while (!remainingKey.empty()) {
            bool isEdgeFound = false;

            for (auto it = current->children.begin(); it != current->children.end(); ++it) {
                string edgeLabel = it->first;
                int commonPrefixLength = findCommonPrefix(remainingKey, edgeLabel);

                if (commonPrefixLength > 0) {
                    isEdgeFound = true;

                    if (commonPrefixLength == edgeLabel.size()) {
                        current = it->second;
                        remainingKey = substring(remainingKey, commonPrefixLength);
                    } else {
                        Node* newNode = new Node();
                        string remainingEdge = substring(edgeLabel, commonPrefixLength);

                        Node* oldChild = it->second;
                        current->children.erase(it);
                        current->children[edgeLabel.substr(0, commonPrefixLength)] = newNode;

                        newNode->children[remainingEdge] = oldChild;

                        if (remainingKey.size() > commonPrefixLength) {
                            string remainingKeyPart = substring(remainingKey, commonPrefixLength);
                            newNode->children[remainingKeyPart] = new Node();
                            newNode->children[remainingKeyPart]->isEnd = true;
                            newNode->children[remainingKeyPart]->mediaMap[film->getname()] = film;
                        } else {
                            newNode->isEnd = true;
                            newNode->mediaMap[film->getname()] = film;
                        }
                    }
                    break;
                }
            }

            if (!isEdgeFound) {
                current->children[remainingKey] = new Node();
                current->children[remainingKey]->isEnd = true;
                current->children[remainingKey]->mediaMap[film->getname()] = film;
                return;
            }
        }

        current->isEnd = true;
        current->mediaMap[film->getname()] = film;

        // Debug: Print the tree structure after inserting each film
        cout << "Inserted: " << film->getname() << endl;
        printTree(root, "");
}

void CompressedTrie::printTree(Node *node, const string &prefix) {
    if (!node) return;

    for (const auto& child : node->children) {
        cout << prefix << child.first << " -> ";
        for (const auto& media : child.second->mediaMap) {
            cout << media.first << " ";
        }
        cout << endl;
        printTree(child.second, prefix + "  ");
    }
}