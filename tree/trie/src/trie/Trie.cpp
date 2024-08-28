#include "Trie.h"

TrieNode::TrieNode() : isEndOfWord(false), countPrefix(0) {}

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    deleteSubtree(root);
}

void Trie::insert(const std::string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        if (!current->children.count(ch)) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
        current->countPrefix++;
    }
    current->isEndOfWord = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* current = root;
    for (char ch : word) {
        if (!current->children.count(ch))
            return false;
        current = current->children[ch];
    }
    return current->isEndOfWord;
}

int Trie::countWordsWithPrefix(const std::string& prefix) {
    TrieNode* current = root;
    for (char ch : prefix) {
        if (!current->children.count(ch))
            return 0;
        current = current->children[ch];
    }
    return current->countPrefix;
}

bool Trie::removeHelper(TrieNode* node, const std::string& word, int depth) {
    if (!node)
        return false;

    if (depth == word.size()) {
        if (node->isEndOfWord) {
            node->isEndOfWord = false;
            node->countPrefix--;
            return node->children.empty();
        }
        return false;
    }

    char ch = word[depth];
    TrieNode* childNode = node->children[ch];

    if (!childNode)
        return false;

    bool shouldDeleteChild = removeHelper(childNode, word, depth + 1);

    if (shouldDeleteChild) {
        delete childNode;
        node->children.erase(ch);
    }

    node->countPrefix--;

    return node->children.empty() && !node->isEndOfWord;
}

void Trie::remove(const std::string& word) {
    removeHelper(root, word, 0);
}

void Trie::deleteSubtree(TrieNode* node) {
    for (auto& child : node->children) {
        deleteSubtree(child.second);
    }
    delete node;
}
