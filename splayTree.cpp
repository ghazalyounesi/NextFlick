//
// Created by ghazal on 1/23/25.
//

#include "splayTree.h"
Node* splayTree::newNode( Media* media) {
    Node* node = new Node();
    node->key = media->getId();
    node->media = media;
    node->left = node->right = nullptr;
    return node;
}

Node* splayTree::rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

Node* splayTree::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node* splayTree::splay(Node* root, int key) {
    if (root == nullptr || root->key == key)
        return root;

    if (root->key > key) {
        if (root->left == nullptr)
            return root;

        if (root->left->key > key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        else if (root->left->key < key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != nullptr)
                root->left = leftRotate(root->left);
        }
        return (root->left == nullptr) ? root : rightRotate(root);
    }
    else {
        if (root->right == nullptr)
            return root;

        if (root->right->key > key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != nullptr)
                root->right = rightRotate(root->right);
        }
        else if (root->right->key < key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        return (root->right == nullptr) ? root : leftRotate(root);
    }
}

void splayTree::insert(Media* media) {
    int key=media->getId();
    if (root == nullptr) {
        root = newNode(media);
        return;
    }

    root = splay(root, key);

    if (root->key == key)
        return;

    Node* node = newNode(media);

    if (root->key > key) {
        node->right = root;
        node->left = root->left;
        root->left = nullptr;
    }
    else {
        node->left = root;
        node->right = root->right;
        root->right = nullptr;
    }
    root = node;
}

Media* splayTree::find(int key) {
    root = splay(root, key);

    if (root != nullptr && root->key == key) {
        return root->media;
    }

    return nullptr;
}

std::string splayTree::findMaxGenreWithDepthScore() {
    if (!root) return "No genres available";
    std::unordered_map<std::string, int> genreScores;

    std::string maxGenre;
    int maxValue = 0;
    std::queue<std::pair<Node*, int>> q;
    q.push({root, 10});

    int currentLevel = 1;

    while (!q.empty()) {
        auto [current, score] = q.front();
        q.pop();

        if (score <= 0) break;

        if (current && current->media) {
            const std::string& genre = current->media->getgenre();
            genreScores[genre] += score;

            if (genreScores[genre] > maxValue) {
                maxValue = genreScores[genre];
                maxGenre = genre;
            }

            if (current->left && score - 1 > 0)
                q.push({current->left, score - 1});
            if (current->right && score - 1 > 0)
                q.push({current->right, score - 1});
        }
    }

    return maxGenre.empty() ? "No genres available" : maxGenre;
}
