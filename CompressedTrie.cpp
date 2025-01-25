#include "CompressedTrie.h"

void CompressedTrie::insert(Media *film) {
    _Node* current = root;
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
                        _Node* newNode = new _Node();
                        string remainingEdge = substring(edgeLabel, commonPrefixLength);

                        _Node* oldChild = it->second;
                        current->children.erase(it);
                        current->children[edgeLabel.substr(0, commonPrefixLength)] = newNode;

                        newNode->children[remainingEdge] = oldChild;

                        if (remainingKey.size() > commonPrefixLength) {
                            string remainingKeyPart = substring(remainingKey, commonPrefixLength);
                            newNode->children[remainingKeyPart] = new _Node();
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
                current->children[remainingKey] = new _Node();
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

void CompressedTrie::printTree(_Node *node, const string &prefix) {
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
void CompressedTrie::collectResults(_Node* node, vector<Media*>& results) {
    if (node->isEnd) {
        for (const auto& mediaPair : node->mediaMap) {
            results.push_back(mediaPair.second);
        }
    }

    for (const auto& child : node->children) {
        collectResults(child.second, results);
    }
}
vector<Media*> CompressedTrie:: search(const string& key) {
    vector<Media*> results;
    _Node* current = root;
    string remainingKey = key;

    while (!remainingKey.empty()) {
        bool isEdgeFound = false;


        for (const auto& it : current->children) {
            string edgeLabel = it.first;
            int commonPrefixLength = findCommonPrefix(remainingKey, edgeLabel);

            if (commonPrefixLength > 0) {
                isEdgeFound = true;

                if (commonPrefixLength == edgeLabel.size()) {
                    current = it.second;
                    remainingKey = substring(remainingKey, commonPrefixLength);


                    if (remainingKey.empty()) {
                        collectResults(current, results);
                    }
                } else {
                    collectResults(it.second, results);
                    remainingKey.clear();
                    break;
                }
                break;
            }
        }

        if (!isEdgeFound) {
            break;
        }
    }

    return results;
}