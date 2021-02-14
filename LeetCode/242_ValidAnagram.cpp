#include<iostream>
using namespace std;
#include<string>
#include<unordered_map>

bool isAnagram(string s, string t) {
	unordered_map<char, int> maps;
	unordered_map<char, int> mapt;

	for(char c : s) maps[c]++;
	for(char c : t){
		maps[c]--;
		if(maps[c]<0) return false;
	}
	for(auto it : maps){
		if(it.second>0) return false;
	}
	return true;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s, t;
	cin>>s>>t;

	cout<<boolalpha<<isAnagram(s, t)<<endl;    

	return 0;
}
