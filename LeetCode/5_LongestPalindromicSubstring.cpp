#include<iostream>
using namespace std;
#include <string>
// #include <unordered_map>
// #include <algorithm>

pair<int, int> expandAroundCenter(string s, int l, int r){
    int tot = r-l+1;
    int len = s.length();
    l--;
    r++;
    while(l>=0 && r<len && s[l]==s[r]){
        l--;
        r++;
    }
    return make_pair(l+1, r-1);
}

string longestPalindrome(string s) {
    int len = s.length();
    pair<int, int> fin;
    fin = make_pair(0, 0);
    for(int i = 0; i<len; i++){
        pair<int, int> temp = expandAroundCenter(s, i, i);
        if(temp.second-temp.first>fin.second-fin.first){
            cout << temp.first << "   " << temp.second<< endl;
            fin = temp;
        }
        if(i<len-1 && s[i]==s[i+1]){
            temp = expandAroundCenter(s, i, i+1);
            if(temp.second-temp.first>fin.second-fin.first){
                cout << temp.first << "   " << temp.second<< endl;
                fin = temp;
            }
        }
        cout << fin.first << "   " << fin.second<< endl;
    }
    cout << fin.first << "   " << fin.second<< endl;
    return s.substr(fin.first, fin.second-fin.first+1);
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    string str;
    getline(cin, str);

    cout << longestPalindrome(str);

	return 0;
}
