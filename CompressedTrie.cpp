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
        /*cout << "Inserted: " << film->getname() << endl;
        printTree(root, "");*/
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
void CompressedTrie::collect(_Node *node, string &currentKey, vector<string> &results) {

    if (node->isEnd) {
        results.push_back(currentKey);
    }
    for (const auto& child : node->children) {
        string temp = currentKey;
        temp += child.first;
        collect(child.second, temp, results);
    }
}

vector<string> CompressedTrie::getAll() {
    vector<string> result;
    string current;
    collect(root,current,result);
    return result;
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

void CompressedTrie::remove(Media *node) {
    _Node* current = root;
    string remainingKey = node->getname();
    vector<_Node*> ancestors;

    while (!remainingKey.empty()) {
        bool isEdgeFound = false;
        for (auto it = current->children.begin(); it != current->children.end(); ++it) {
            string edgeLabel = it->first;
            int commonPrefixLength = findCommonPrefix(remainingKey, edgeLabel);

            if (commonPrefixLength > 0) {
                isEdgeFound = true;
                if (commonPrefixLength == edgeLabel.size()) {
                    current = it->second;
                    ancestors.push_back(current);
                    remainingKey = substring(remainingKey, commonPrefixLength);
                } else {
                    return;
                }
                break;
            }
        }
        if (!isEdgeFound) {
            return;
        }
    }

    if (current->isEnd) {
        current->isEnd = false;
        current->mediaMap.erase(node->getname());
    }

    for (auto it = ancestors.rbegin(); it != ancestors.rend(); ++it) {
        _Node* ancestor = *it;

        if (ancestor->children.empty() && !ancestor->isEnd) {
            if (ancestor == root) break;
            delete ancestor;
        } else {
            break;
        }
    }
}