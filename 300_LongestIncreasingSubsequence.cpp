#include<iostream>
using namespace std;
#include<vector>
#include<list>

int lengthOfLIS(vector<int>& nums) {
	list<int> memo;
	memo.push_front(1);
	for(int i = nums.size()-2; i>=0; i--){
		int maxi = 0;
		int j = 0;
		for(int num : memo){
			// cout<<nums[i]<<"  "<<nums[i+j+1]<<"   "<<num<<endl;
			if(nums[i+j+1]>nums[i]) maxi = max(maxi, num);
			j++;
		}
		// cout<<endl<<endl;
		memo.push_front(maxi+1);
	}
	int maxi = 0;
	for(int i : memo){
		if(maxi<i) maxi = i;
	}
	return maxi;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    vector<int> nums;
    int input;
    while(cin>>input) nums.push_back(input);

	cout<<lengthOfLIS(nums)<<endl;    

	return 0;
}
