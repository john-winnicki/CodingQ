#include<iostream>
using namespace std;
#include<vector>

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	
	int n = intervals.size();

	int start_ind = 0;
	for(int i = 0; i<n; i++){
		if(newInterval[0]<intervals[i][0]) break;
		else start_ind++;
	}
	intervals.insert(intervals.begin()+start_ind, newInterval);
	// for(int i = 0; i<n+1; i++){
		// cout<<intervals[i][0]<<"  "<<intervals[i][1]<<endl;
	// }

	vector<vector<int>> fin;
	vector<int> temp = intervals[0];
	for(int i = 0; i<n+1; i++){
		if(temp[1]>=intervals[i][0]){
			temp[1] = max(temp[1], intervals[i][1]);
		}
		else{
			fin.push_back(temp);
			temp = intervals[i];
		}
	}
	fin.push_back(temp);
	return fin;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> insertion;
	int input;
	cin>>input;
	insertion.push_back(input);
	cin>>input;
	insertion.push_back(input);

    vector<vector<int>> pairs;

    while(cin>>input){
    	vector<int> temp;
    	temp.push_back(input);
    	cin>>input;
    	temp.push_back(input);
    	pairs.push_back(temp);
    }

	for(vector<int> pairy : pairs){
		cout<<pairy[0]<<"   "<<pairy[1]<<endl;
    }

    cout<<endl<<endl;

    vector<vector<int>> fin = insert(pairs, insertion);
    for(vector<int> pairy : fin){
    	cout<<pairy[0]<<"   "<<pairy[1]<<endl;
    }

	return 0;
}
