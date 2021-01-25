#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<unordered_set>

void dfs(vector<vector<char>>& board, int y, int x, unordered_set<string>& preword, unordered_set<string>& dict, vector<vector<bool>>& seen, vector<string>& fin, string& curr){
	cout<<board[y][x]<<endl;
	curr += board[y][x];
	if(dict.find(curr)!=dict.end()){
		cout<<"CURR FOUND HERE: "<<curr<<endl;
		fin.push_back(curr);
		dict.erase(curr);
	}
	cout<<curr<<endl;
	if(preword.find(curr)==preword.end()){
		curr.pop_back();
		return;
	}
	cout<<"preword found for: "<<board[y][x]<<endl;
	seen[y][x] = true;
	if(y-1>=0 && !seen[y-1][x]) dfs(board, y-1, x, preword, dict, seen, fin, curr);
	if(y+1<board.size() && !seen[y+1][x]) dfs(board, y+1, x, preword, dict, seen, fin, curr);
	if(x-1>=0 && !seen[y][x-1]) dfs(board, y, x-1, preword, dict, seen, fin, curr);
	if(x+1<board[0].size() && !seen[y][x+1]) dfs(board, y, x+1, preword, dict, seen, fin, curr);
	curr.pop_back();
	seen[y][x] = false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    unordered_set<string> dict(words.begin(), words.end());
    unordered_set<string> preword;
    for(string s : words){
    	string temp = "";
    	for(int i = 0; i<s.length(); i++){
    		temp += s[i];
    		preword.insert(temp);
    	}
    }

    // for(string s : preword) cout<<s<<endl;

    vector<string> fin;
	for(int i = 0; i<board.size(); i++){
		for(int j = 0; j<board[0].size(); j++){
			vector<vector<bool>> seen(board.size(), vector<bool>(board[0].size(), false));
			string temp = "";
			dfs(board, i, j, preword, dict, seen, fin, temp);
			cout<<endl<<endl;
		}
	}

	return fin;    
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int m, n;
    cin>>m>>n;

    char input;
	vector<vector<char>> board;
	for(int i = 0; i<m; i++){
		vector<char> row;
		for(int j = 0; j<n; j++){
			cin>>input;
			row.push_back(input);
		}
		board.push_back(row);
	}

	vector<string> words;
	string lala;
	while(cin>>lala) words.push_back(lala);

	vector<string> fin = findWords(board, words);

	for(string s : fin) cout<<s<<"  ";

	return 0;
}
