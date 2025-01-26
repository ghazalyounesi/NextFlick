//
// Created by ghazal on 1/26/25.
//

#ifndef NEXTFLICK_DECISIONTREE_H
#define NEXTFLICK_DECISIONTREE_H
#include <iostream>
#include <string>
#include "Media.h"
#include "GlobalSparset.h"


struct DecisionTreeNode {
    double threshold;
    std::vector<int> movieIds;
    DecisionTreeNode* left;
    DecisionTreeNode* right;

    DecisionTreeNode(double threshold)
            : threshold(threshold), left(nullptr), right(nullptr) {}
};

class DecisionTree {
private:
    DecisionTreeNode* root;

    void deleteTree(DecisionTreeNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    DecisionTreeNode* insertNode(DecisionTreeNode* node, int id, double rating) {
        if (!node) {
            return nullptr;
        }

        if (!node->left && !node->right) {

            node->movieIds.push_back(id);
        } else if (rating <= node->threshold) {
            node->left = insertNode(node->left, id, rating);
        } else {
            node->right = insertNode(node->right, id, rating);
        }
        return node;
    }

    void traverseTree(DecisionTreeNode* node, int depth = 0) const {
        if (!node) return;

        for (int i = 0; i < depth; ++i) std::cout << "  ";
        std::cout << "Threshold: " << node->threshold << ", Movie IDs: ";
        for (int id : node->movieIds) {
            std::cout << id << " ";
        }
        std::cout << "\n";

        traverseTree(node->left, depth + 1);
        traverseTree(node->right, depth + 1);
    }

    Media* getMediaById(int id) const {
        return sparseSetMedia[id];
    }
    DecisionTreeNode* removeNode(DecisionTreeNode* node, int id) {
        if (!node) return nullptr;

        if (!node->left && !node->right) {

            for (size_t i = 0; i < node->movieIds.size(); ++i) {
                if (node->movieIds[i] == id) {
                    node->movieIds.erase(node->movieIds.begin() + i);
                    break;
                }
            }

            if (node->movieIds.empty()) {
                delete node;
                return nullptr;
            }
        } else {
            Media* media = getMediaById(id);
            if (media) {
                double rating = media->getrating();
                if (rating <= node->threshold) {
                    node->left = removeNode(node->left, id);
                } else {
                    node->right = removeNode(node->right, id);
                }
            }
        }

        return node;
    }

public:
    DecisionTree() : root(nullptr) {}

    ~DecisionTree() {
        deleteTree(root);
    }

    void buildTree() {
        root = new DecisionTreeNode(5.0);
        root->left = new DecisionTreeNode(3.0);
        root->right = new DecisionTreeNode(8.0);

        root->left->left = new DecisionTreeNode(2.0);
        root->left->right = new DecisionTreeNode(4.0);

        root->right->left = new DecisionTreeNode(6.0);
        root->right->right = new DecisionTreeNode(9.0);
    }

    void insert(int id) {
        Media* media = getMediaById(id);
        if (!media) {
            std::cout << "Media not found for ID: " << id << "\n";
            return;
        }
        root = insertNode(root, id, media->getrating());
    }

    void query() const {
        DecisionTreeNode* current = root;
        while (current) {
            if (!current->left && !current->right) {
                std::cout << "فیلم‌هایی با ID: ";
                for (int id : current->movieIds) {
                    std::cout << id << " ";
                }
                std::cout << "پیدا شدند.\n";
                break;
            }

            std::cout << "آیا فیلم‌هایی با امتیاز بالای " << current->threshold << " را می‌خواهید؟ (y/n): ";
            char answer;
            std::cin >> answer;

            if (answer == 'y' || answer == 'Y') {
                current = current->right;
            } else if (answer == 'n' || answer == 'N') {
                current = current->left;
            } else {
                std::cout << "ورودی نامعتبر!\n";
            }
        }
    }

    void traverse() const {
        traverseTree(root);
    }
    void remove(int id) {
        root = removeNode(root, id);
    }

};


#endif //NEXTFLICK_DECISIONTREE_H
