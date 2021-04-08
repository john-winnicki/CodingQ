// using namespace std;
// using string 
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

void solve(string s, int k){
	
	int freqs[26] = {0};
	for(char c : s) freqs[c-'a'] += 1;

	while(k>0){
		int mini = -1;
		for(int i = 0; i<26; i++){
			if((mini==-1 || freqs[mini]>freqs[i]) && freqs[i]!=0) mini = i;
		}		
		if(mini==-1){
			cout<<0<<endl;
			return;
		}

		if(freqs[mini]>k){
			k = 0;
		}
		else{
			k -= freqs[mini];
			freqs[mini] = 0;
		}
	}

	int finCount = 0;
	for(int i = 0; i<26; i++) finCount += freqs[i]>0 ? 1 : 0;

	string fin = "";
	for(char c : s){
		if(freqs[c-'a']>0){
			freqs[c-'a']--;
			fin += c;
		}
	}
	cout<<finCount<<endl;
	cout<<fin<<endl;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
	#endif

    string s;
    getline(cin, s);

    int k; 
    cin>>k;

    solve(s, k);

	return 0;
}
