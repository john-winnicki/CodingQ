#include<iostream>
using namespace std;
#include <string>
#include <unordered_map>
#include <algorithm>

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash;
    int len = s.length();
    if(len==0) return 0;
    int start = 0;
    int maxi = 0;
    for(int i = 0; i<len; i++){
        if(hash.find(s[i])!=hash.end() && hash[s[i]]>=start){
            start = hash[s[i]] + 1;
        }
        hash[s[i]] = i;
        maxi = max(i-start, maxi);
    }
    return maxi+1;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    string str;
    getline(cin, str);

    cout << lengthOfLongestSubstring(str);

	return 0;
}
