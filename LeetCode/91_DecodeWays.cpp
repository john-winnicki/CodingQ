#include<iostream>
using namespace std;
#include<string>
#include<vector>

bool isValid(int a, int b){
	a -= '0';
	b -= '0';
	if(a==0) return false;
	else if(a==1) return true;
	else if(a==2){
		if(b<=6) return true;
		else return false;
	}
	else return false;
}

int numDecodings(string s) {
	// cout<<s<<endl;
	int len = s.length();
	vector<int> memo(s.length(), 0);
	memo[0] = s[0]!='0';
	// cout<<memo[0]<<endl;
	if(len==1) return memo[0];
	memo[1] = s[1]!='0' ? memo[0] : 0;
	memo[1] += isValid(s[0], s[1]) ? 1 : 0;
	// cout<<memo[1]<<endl;
	for(int i = 2; i<len; i++){
		memo[i] += s[i]!='0' ? memo[i-1] : 0;
		memo[i] += isValid(s[i-1], s[i]) ? memo[i-2] : 0;
		// cout<<memo[i]<<endl;
	}
	return memo[len-1];

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    string str;
    cin>>str;

    cout<<numDecodings(str);

	return 0;
}
