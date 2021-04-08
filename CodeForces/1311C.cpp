// using namespace std;
// using string 
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

void solve(int n, int m, string s, vector<int> &arr){
	vector<int> freqs(26, 0);
	for(int i = 0; i<m; i++){
		for(int j = 0; j<arr[i]; j++){
			freqs[s[j]-'a']++;
		}
	}

	for(char c : s) freqs[c-'a']++;
	for(int i = 0; i<26; i++) cout<<freqs[i]<<" ";
	cout<<endl;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
	#endif

    
    int t; 
    cin>>t;

    for(int i = 0; i<t; i++){
    	int n,m;
    	cin>>n>>m;
    	string s;
    	cin>>s;
    	vector<int> curr;
    	int input;
    	for(int j = 0; j<m; j++){
    		cin>>input;
    		curr.push_back(input);
    	}
    	solve(n, m, s, curr);
    }

	return 0;
}
