// using namespace std;
// using string 
#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

void permuter5(vector<vector<int>> &tot, vector<int>& curr, int index){
	if(index==5){
		tot.push_back(vector<int>(curr));
		return;
	}
	else{
		for(int i = index; i<5; i++){
			swap(curr[index], curr[i]);
			permuter5(tot, curr, index+1);
			swap(curr[index], curr[i]);
		}
	}
}

void solve(vector<vector<int>> &matrix){
	vector<vector<int>> permutesOf5;
	vector<int> lst {0, 1, 2, 3, 4};
	permuter5(permutesOf5, lst, 0);

	int max_num = 0;
	for(vector<int> vec : permutesOf5){
		
		int a = vec[0];
		int b = vec[1];
		int c = vec[2];
		int d = vec[3];
		int e = vec[4];

		int num = matrix[a][b] + matrix[b][a] + matrix[c][d] + matrix[d][c]
		+ matrix[b][c] + matrix[c][b] + matrix[d][e] + matrix[e][d]
		+ matrix[c][d] + matrix[d][c] + matrix[d][e] + matrix[e][d];
		max_num = max(num, max_num);
	}
	cout<<max_num<<endl;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
	#endif

    vector<vector<int>> matrix;
    for(int i = 0; i<5; i++){
    	vector<int> curr;
    	int input;
    	for(int j = 0; j<5; j++){
    		cin>>input;
    		curr.push_back(input);
    	}
    	matrix.push_back(curr);
    }
    solve(matrix);

	return 0;
}
