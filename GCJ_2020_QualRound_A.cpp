#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>

void sol(int num, vector<vector<int>> matrix){
	int row_count = 0;
	int col_count = 0;
	int trace = 0;
	
	int m = matrix.size();

	for(int i = 0; i<m; i++){
		unordered_set<int> temp;
		for(int j = 0; j<m; j++){
			if(temp.find(matrix[i][j])==temp.end()) temp.insert(matrix[i][j]);
			else{
				row_count+=1; 
				break;
			}
		}
	}

	for(int j = 0; j<m; j++){
		unordered_set<int> temp;
		for(int i = 0; i<m; i++){
			if(temp.find(matrix[i][j])==temp.end()) temp.insert(matrix[i][j]);
			else{
				col_count+=1; 
				break;
			}
		}
	}

	for(int i = 0; i<m; i++){
		trace += matrix[i][i];
	}

	cout<<"Case #"<<num<<": "<<trace<<" "<<row_count<<" "<<col_count<<endl;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int input;
	cin>>input;

    for(int i = 1; i<=input; i++){
    	int m;
    	cin>>m;
    	vector<vector<int>> matrix(m, vector<int>(m));
	    for(int i = 0; i<m; i++){
	    	for(int j = 0; j<m; j++){
	    		cin>>matrix[i][j];
	    	}
	    }
	    sol(i, matrix);
    }

	return 0;
}
