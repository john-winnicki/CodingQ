#include<iostream>
using namespace std;
#include<vector>

int uniquePaths(int m, int n) {
	vector<vector<int>> memo(m, vector<int>(n, 0));
	for(int i = 0; i<m; i++) memo[i][0] = 1;
	for(int i = 0; i<n; i++) memo[0][i] = 1;
	for(int i = 1; i<m; i++){
		for(int j = 1; j<n; j++){
			memo[i][j] = memo[i-1][j] + memo[i][j-1];
		}
	}
	return memo[m-1][n-1];        
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int m, n;
    cin>>m>>n;

    cout<<uniquePaths(m, n)<<endl;

	return 0;
}
