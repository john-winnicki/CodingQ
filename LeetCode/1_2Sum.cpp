#include<iostream>
using namespace std;
#include <vector>
#include <unordered_map>


vector<int> twosum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    vector<int> fin;
    for(int i = 0; i<nums.size(); i++){
    	int ntarg = target-nums[i];
    	if(map.find(ntarg)!=map.end()){
    		fin.push_back(i);
    		fin.push_back(map[ntarg]);
    		return fin;
    	}
    	map[nums[i]] = i;
    }
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
    while(cin >> input) arr.push_back(input);

	vector<int> fin = twosum(arr, target);

	// for(int i = 0; i<len; i++) cout << nums[i] << endl;
	cout << fin[0] << "   " << fin[1];

	return 0;
}
