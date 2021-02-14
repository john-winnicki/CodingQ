#include<iostream>
using namespace std;
#include<vector>

void setZeroes(vector<vector<int>>& matrix) {

	int m = matrix.size();
	int n = matrix[0].size();

	bool cancel_toprow = false;
	bool cancel_leftcol = false;

	for(int i = 0; i<m; i++){
		if(matrix[i][0]==0){
			cancel_toprow = true;
		}
	}
	for(int j = 0; j<n; j++){
		if(matrix[0][j]==0){
			cancel_leftcol = true;
		}
	}

	for(int i = 1; i<m; i++){
		for(int j = 1; j<n; j++){
			if(matrix[i][j]==0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for(int i = 1; i<m; i++){
		if(matrix[i][0]==0){
			for(int j = 0; j<n; j++) matrix[i][j] = 0;
		}
	}
	for(int j = 1; j<n; j++){
		if(matrix[0][j]==0){
			for(int i = 0; i<m; i++) matrix[i][j] = 0;
		}
	}

	if(cancel_leftcol){
		for(int i = 0; i<m; i++) matrix[i][0] = 0;
	}
	if(cancel_toprow){
		for(int j = 0; j<n; j++) matrix[0][j] = 0;
	}
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int m, n;
    cin>>m>>n;

    int input;
    vector<vector<int>> matrix;

    for(int i = 0; i<m; i++){
    	vector<int> temp;
    	for(int j = 0; j<n; j++){
    		cin>>input;
    		temp.push_back(input);
    	}
    	matrix.push_back(temp);
    }

	for(vector<int> i : matrix){
		for(int j : i) cout<<j<<"  ";
		cout<<endl;
	}
	cout<<endl<<endl;

    setZeroes(matrix);

    for(vector<int> i : matrix){
    	for(int j : i) cout<<j<<"  ";
    	cout<<endl;
    }

	return 0;
}
