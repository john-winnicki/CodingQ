#include<iostream>
using namespace std;
#include<vector>
#include<string>

bool dfs(vector<vector<char>>& board, string word, int pos, int y, int x, vector<vector<bool>>& visited){
	// cout<<word<<endl;
	// cout<<board[y][x];
	// cout<<y<<"  "<<x<<endl;
	if(pos==word.length()) return true;
	if(board[y][x]!=word[pos]) return false;
	else pos++;
	if(pos==word.length()) return true;
	visited[y][x] = true;
	if(y-1>=0 && !visited[y-1][x] && dfs(board, word, pos, y-1, x, visited)) return true;
	if(y+1<board.size() && !visited[y+1][x] && dfs(board, word, pos, y+1, x, visited)) return true;
	if(x-1>=0 && !visited[y][x-1] && dfs(board, word, pos, y, x-1, visited)) return true;
	if(x+1<board[0].size() && !visited[y][x+1] && dfs(board, word, pos, y, x+1, visited)) return true;
	visited[y][x] = false;
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

	// return dfs(board, word, 0, 0, 0, visited);

	for(int i = 0; i<board.size(); i++){
		for(int j = 0; j<board[0].size(); j++){
			if(dfs(board, word, 0, i, j, visited)) return true;
		}
	}
	return false;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string word;
	cin>>word;

    int m, n;
    cin>>m>>n;
    char input;
    vector<vector<char>> board;
    for(int i = 0; i<m; i++){
    	vector<char> temp;
    	for(int j = 0; j<n; j++){
    		cin>>input;
    		temp.push_back(input);
    	}
    	board.push_back(temp);
    }

    cout<<boolalpha<<exist(board, word);

	return 0;
}
