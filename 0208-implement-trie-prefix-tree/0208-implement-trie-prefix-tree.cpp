class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
private:
    TrieNode* root;

    void insertUtil(TrieNode* &root, string word) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        TrieNode* child;
        int index = word[0] - 'a';

        if(root->children[index] == NULL) {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        } else {
            child = root->children[index];
        }

        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode* &root, string word) {
        if(word.length() == 0) {
            return root->isTerminal;
        }

        TrieNode* child;
        int index = word[0] - 'a';

        if(root->children[index] == NULL) {
            return false;
        } else {
            child = root->children[index];
        }

        return searchUtil(child, word.substr(1));
    }

    bool startsWithUtil(TrieNode* &root, string word) {
        if(word.length() == 0) {
            return true;
        }

        TrieNode* child;
        int index = word[0] - 'a';

        if(root->children[index] == NULL) {
            return false;
        } else {
            child = root->children[index];
        }

        return startsWithUtil(child, word.substr(1));
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insert(string word) {
        insertUtil(root, word);
    }
    
    bool search(string word) {
        return searchUtil(root, word);
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */