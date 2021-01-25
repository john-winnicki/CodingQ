class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length()==0) return true;
        if(wordDict.size()==0) return false;
        
        int len = s.length();
        
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        
        vector<bool> memo(len, false);
        
        for(int i = 0; i<len; i++){
            for(int j = 0; j<=i; j++){
                if((j>0 ? memo[j-1]:true) && hash.find(s.substr(j, i-j+1))!=hash.end()){
                    memo[i] = true;
                    break;
                }
            }
        }
        // for(bool i : memo) cout<<boolalpha<<i<<endl;
        return memo[len-1];
    }
};