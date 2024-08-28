#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>

class Trie {
private:
    TrieNode* root;

    bool removeHelper(TrieNode* node, const std::string& word, int depth);
    
    void deleteSubtree(TrieNode* node);

public:
    Trie();
    ~Trie();

    void insert(const std::string& word);

    bool search(const std::string& word);

    int countWordsWithPrefix(const std::string& prefix);

    void remove(const std::string& word);
};

#endif
