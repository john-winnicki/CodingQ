class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        TrieNode *lets[26];
        bool isWord = false;
    };
    
    TrieNode *head;
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = head;
        for(char c : word){
            if(curr->lets[c-'a']==nullptr){
                curr->lets[c-'a'] = new TrieNode();
            }
            curr = curr->lets[c-'a'];
        }
        curr->isWord = true;
    }
    
    bool searchUtil(string word, TrieNode *curr, int pos){
        if(pos==word.length()) return curr->isWord;
        else{
            if(word[pos]=='.'){
                for(TrieNode* temp : curr->lets){
                    if(temp!=nullptr){
                        if(searchUtil(word, temp, pos+1)) return true;
                    }
                }
                return false;
            }
            else{
                if(curr->lets[word[pos]-'a']!=nullptr){
                    return searchUtil(word, curr->lets[word[pos]-'a'], pos+1);
                }
                else return false;
            }
        }
    }
    
    bool search(string word) {
        return searchUtil(word, head, 0);
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */