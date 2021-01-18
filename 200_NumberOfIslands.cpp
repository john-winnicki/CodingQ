#include<iostream>
using namespace std;
#include <vector>


void dfs(vector<vector<char>>& grid, int y, int x){
    grid[y][x]='0';
    if((y-1>=0) && (grid[y-1][x]=='1')) dfs(grid, y-1, x);
    if((y+1<grid.size()) && (grid[y+1][x]=='1')) dfs(grid, y+1, x);
    if((x-1>=0) && (grid[y][x-1]=='1')) dfs(grid, y, x-1);
    if((x+1<grid[0].size()) && (grid[y][x+1]=='1')) dfs(grid, y, x+1);
    // cout << "hi";
}

int numIslands(vector<vector<char>>& grid) {
    int num = 0;
    for(int i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid[0].size(); j++){

        	cout << grid[i][j] << " ";
            if(grid[i][j]=='1'){
                num++;
                dfs(grid, i, j);
            }
        }
        cout<< endl;
    }
    return num;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	int m, n;
	cin >> m >> n;

	vector<vector<char>> grid(m);

	for(int i = 0; i<m; i++){
		vector<char> row(n);
		for(int j = 0; j<n; j++){
			cin >> row[j];
		}
		grid[i] = row;
	}

	cout << numIslands(grid);

	// for(int i = 0; i<len; i++) cout << nums[i] << endl;

	return 0;
}
