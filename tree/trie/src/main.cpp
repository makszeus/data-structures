#include <iostream>
#include "Trie.h"

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("apex");
    trie.insert("bat");
    trie.insert("batch");

    std::cout << "Words with prefix 'app': " << trie.countWordsWithPrefix("app") << std::endl;
    
    trie.remove("app");

    std::cout << "Words with prefix 'app' after removal: " << trie.countWordsWithPrefix("app") << std::endl;

    return 0;
}
