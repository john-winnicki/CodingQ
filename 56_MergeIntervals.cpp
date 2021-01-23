#include<iostream>
using namespace std;
#include<vector>


vector<vector<int>> merge(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)->bool
	{
		return a[0]<b[0];
	});

	vector<vector<int>> fin;
	vector<int> temp = intervals[0];
	for(int i = 0; i<intervals.size(); i++){
		if(temp[1]>=intervals[i][0]){
			temp[1] = max(intervals[i][1], temp[1]);
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


	vector<vector<int>> pairs;
	int input;

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

    vector<vector<int>> fin = merge(pairs);
    for(vector<int> pairy : fin){
    	cout<<pairy[0]<<"   "<<pairy[1]<<endl;
    }

	return 0;
}
