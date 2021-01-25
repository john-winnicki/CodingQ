class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        TrieNode* lets[26];
        bool isWord = false;
    };
    
    TrieNode *head;
    Trie() {
        head = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = head;
        for(char c : word){
            if((curr->lets)[c-'a']==nullptr){
                TrieNode* temp = new TrieNode();
                (curr->lets)[c-'a'] = temp; 
            }
            curr = (curr->lets)[c-'a'];
        }
        curr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = head;
        for(char c : word){
            if((curr->lets)[c-'a']==nullptr) return false;
            else curr = (curr->lets)[c-'a'];
        }
        return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = head;
        for(char c : prefix){
            if((curr->lets)[c-'a']==nullptr) return false;
            else curr = (curr->lets)[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */