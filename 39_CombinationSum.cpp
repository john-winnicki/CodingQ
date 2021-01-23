#include<iostream>
using namespace std;
#include<vector>

void combUtil(vector<int>& candidates, vector<int>& curr, int target, vector<vector<int>>& fin, int start){
	if(target==0){
		fin.push_back(vector<int>(curr));
	}
	for(int j = start; j<candidates.size(); j++){
		int i = candidates[j];
		if(target-i<0) break;
		curr.push_back(i);
		combUtil(candidates, curr, target-i, fin, j);
		curr.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> fin;
	vector<int> curr;
	combUtil(candidates, curr, target, fin, 0);
	return fin;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int target;
   	cin >> target;
   	
   	vector<int> arr;

   	int input;
   	while(cin >> input){
   		arr.push_back(input);
   	}

   	vector<vector<int>> fin = combinationSum(arr, target);
   	for(vector<int> vec : fin){
   		for(int i : vec) cout << i;
   		cout << endl;
   	}

	return 0;
}
