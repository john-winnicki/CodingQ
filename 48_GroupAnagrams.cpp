#include<iostream>
using namespace std;
#include<string>
#include<list>
#include<unordered_map>
#include<vector>

string hashit(string s){
	int arr[26];

	fill(begin(arr), begin(arr)+26, 0);

	for(char c : s){
		// cout<<endl<<endl<<c-'a'<<endl<<endl;
		arr[c-'a']++;
	}
	string fin = "";
	for(int i = 0; i<26; i++){
		fin += to_string(arr[i])+"*";
	}
	// cout << fin<< endl;
	return fin;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, list<string>> map;
	for(string s : strs){
		string hashed = hashit(s);
		if(map.find(hashed)==map.end()){
			// list<string>* li = new list<string>();
			list<string> li;
			map.insert({hashed, li});
		}
		map[hashed].push_back(s);
		// for(string sn : map[hashed]) cout<<"map item: "<<sn<<endl;
		// cout<<endl<<endl;
	}
	vector<vector<string>> fin;
	for(auto it : map){
		vector<string> mini;
		for(string s : it.second){
			mini.push_back(s);
		}
		fin.push_back(mini);
	}
	return fin;
}	

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    vector<string> strs;
    string input;
    while(cin>>input){
    	strs.push_back(input);
    }

    vector<vector<string>> fin = groupAnagrams(strs);

    for(vector<string> i : fin){
    	for(string s : i){
    		cout<<s<<"    ";
    	}
		cout<<endl;
    }

	return 0;
}
