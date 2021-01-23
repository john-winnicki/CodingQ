#include<iostream>
using namespace std;
#include<string>
#include<unordered_set>
#include<vector>

bool isGood(int arr[]){
	for(int i = 0; i<128; i++){
		if(arr[i]>0) return false;
	}
	return true;
}


// string minWindow(string s, string t) {
// 	if(t.length()==0 || s.length()==0) return "";
// 	// cout<<s<<endl<<t<<endl;
// 	int slen = s.length();

//     int arr[128];
// 	fill(arr, arr+128, 0);
    
//     unordered_set<char> hash;

//     for(char c : t){
//         arr[c-'A']++;
//         hash.emplace(c);
//     }

//     int l = 0;
//     int r = 0;

//     // for(int i = 0; i<128; i++) cout<<arr[i]<<endl;

//     while(!isGood(arr)){
//     	// for(int i = 0; i<26; i++) cout<<arr[i]<<"  ";
//     	// cout<<endl;
//     	if(hash.find(s[r])!=hash.end()){
//     		arr[s[r]-'A']--;
//     	}
//     	r++;
//     	if(r==slen) break;
//     }

//     while(isGood(arr)){
//     	if(hash.find(s[l])!=hash.end()){
//     		if(arr[s[l]-'A']==0) break;
//     		arr[s[l]-'A']++;
//     	}
//     	l++;
//     }
    
//     string curr = "";
//     if(isGood(arr)){
// 		curr = s.substr(l, r);    	
//     }

//     while(l<slen && r<slen){
//     	while(l<=r && isGood(arr)){
//     		cout<<l<< "   " << r<<endl;
//     		if(curr.length()>(r-l)) curr = s.substr(l, r-l);
//     		if(hash.find(s[l])!=hash.end()){
//     			arr[s[l]-'A']++;
//     		}
//     		l++;
//     	}
//     	while(l<=r&&hash.find(s[l])==hash.end()) l++;
//     	while(!isGood(arr) && r<slen){
//     		cout<<l<< "   " << r<<endl;
//     		if(hash.find(s[r])!=hash.end()){
//     			arr[s[r]-'A']--;
//     		}
//     		r++;
//     	}
//     	if(isGood(arr)){
//     		if(curr.length()>(r-l)) curr = s.substr(l, r-l);
//     	}
//     	if(r==slen){
//     		while(l<=r && isGood(arr)){
// 	    		cout<<l<< "   " << r<<endl;
// 	    		if(curr.length()>(r-l)) curr = s.substr(l, r-l);
// 	    		if(hash.find(s[l])!=hash.end()){
// 	    			arr[s[l]-'A']++;
// 	    		}
// 	    		l++;

//     		}
//     		cout<<l<< "   " << r<<endl;
//     	}
//     }
//     return curr;   
// }

//SOMEONE ELSES SOLUTION
string minWindow(string s, string t) {
    string res = "";
    vector<int> m(128,0);  // used to use map
    int left = 0, count = 0, minLen = INT_MAX;
    for (char c : t) ++m[c];
    for (int i=0; i<s.size(); ++i) {
        if (--m[s[i]]>=0) ++count;
        while (count == t.size()) {
            if (minLen > i-left+1) {
                minLen = i-left+1;
                res = s.substr(left, minLen);
            }
            if (++m[s[left]]>0) --count;
            ++left;
        }
    }
    return res;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    string s,t;
    cin>>s>>t;

    cout<<minWindow(s, t);

	return 0;
}
