class Trie {
public:
    Trie **child;
    bool finish;
    /** Initialize your data structure here. */
    Trie() {
        child = new Trie* [26];
        for(int i =0; i< 26; i++)
        {
            child[i] = NULL;
        }
        finish = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(int i = 0; i< word.length(); i++)
        {
            int index = word[i] - 'a';
            if(root->child[index] == NULL)
                root->child[index] = new Trie();
            root = root->child[index];
        }
        root->finish = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for(int i =0 ;i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if(root->child[index] == NULL)
                return false;
            else
            {
                root = root -> child[index];
            }
        }
        return root->finish;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for(int i =0 ;i < prefix.length(); i++)
        {
            int index = prefix[i] - 'a';
            if(root->child[index] == NULL)
                return false;
            else
            {
                root = root -> child[index];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
