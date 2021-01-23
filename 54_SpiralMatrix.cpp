#include<iostream>
using namespace std;
#include<vector>
typedef pair<int, int> pi;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	pi tl = make_pair(0, 0);
	pi tr = make_pair(0, n-1);
	pi br = make_pair(m-1, n-1);
	pi bl = make_pair(m-1, 0);

	vector<int> fin;

	while(tl.second<tr.second && tr.first<br.first){
		cout<<tl.first<<"  "<<tl.second<<endl;
		pi ntl = pair<int, int>(tl);
		pi ntr = pair<int, int>(tr);
		pi nbr = pair<int, int>(br);
		pi nbl = pair<int, int>(bl);

		while(ntl.second<ntr.second){
			fin.push_back(matrix[ntl.first][ntl.second]);
			ntl.second++;
		}
		while(ntr.first<nbr.first){
			fin.push_back(matrix[ntr.first][ntr.second]);
			ntr.first++;
		}
		while(nbr.second>nbl.second){
			fin.push_back(matrix[nbr.first][nbr.second]);
			nbr.second--;
		}
		while(nbl.first>ntl.first){
			fin.push_back(matrix[nbl.first][nbl.second]);
			nbl.first--;
		}
		tl.first++;
		tl.second++;
		tr.first++;
		tr.second--;
		br.first--;
		br.second--;
		bl.first--;
		bl.second++;
	}

	if(tl.second>tr.second || tl.first>bl.first) return fin;
	while(tl.second<tr.second){
		fin.push_back(matrix[tl.first][tl.second]);
		tl.second++;
	}
	// tl.first++;
	while(tl.first<=bl.first){
		fin.push_back(matrix[tl.first][tl.second]);
		tl.first++;
    }
	return fin;
	// if(tl.second>tr.second && tr.first>br.first) return fin;
	// else if((tl.second>=tr.second)&&(tr.first>=br.first)){
	// 	fin.push_back(matrix[tl.first][tl.second]);
	// }
	// else if(tl.second<tr.second){
	// 	while(tl.second<=tr.second){
	// 		fin.push_back(matrix[tl.first][tl.second]);
	// 		tl.second++;
	// 	}
	// }
	// else{
	// 	while(tr.first<=br.first){
	// 		fin.push_back(matrix[tr.first][tr.second]);
	// 		tr.first++;
	// 	}
	// }

	return fin;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix;

    int input;
    for(int i = 0; i<m; i++){
    	vector<int> row;
    	for(int j = 0; j<n; j++){
    		cin>>input;
    		row.push_back(input);
    	}
    	matrix.push_back(row);
    }

    vector<int> fin = spiralOrder(matrix);

    for(int i : fin) cout<<i<<"  ";

	return 0;
}
