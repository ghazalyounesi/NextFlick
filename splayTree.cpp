//
// Created by ghazal on 1/23/25.
//

#include "splayTree.h"
Node* splayTree::newNode(int id) {
    Node* node = new Node();
    node->key = id;
    //node->media = media;
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

void splayTree::insert(int Id) {
    int key=Id;
    if (root == nullptr) {
        root = newNode(Id);
        return;
    }

    root = splay(root, key);

    if (root->key == key)
        return;

    Node* node = newNode(Id);

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
        if(sparseSetMedia[key]){
            return sparseSetMedia[key];
        }
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

        if (current && sparseSetMedia[current->key]) {
            const std::string& genre = sparseSetMedia[current->key]->getgenre();
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

int splayTree::depth(int id) {
    int d = 0;
    Node* temp = root;

    while (temp != nullptr) {
        if (id == temp->key) {
            return d;
        }

        if (id < temp->key) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        d++;
    }
    return -1;
}


Node* splayTree:: delete_key(struct Node* root, int key)
{
    Node* temp;
    if (!root)
        return NULL;

    root = splay(root, key);

    if (key != root->key)
        return root;

    if (!root->left) {
        temp = root;
        root = root->right;
    }
    else {
        temp = root;
        root = splay(root->left, key);
        root->right = temp->right;
    }
    free(temp);

    return root;
}
