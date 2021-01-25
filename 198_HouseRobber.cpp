#include<iostream>
using namespace std;
#include<vector>

int rob(vector<int>& nums) {
	if(nums.size()==0) return 0;
	if(nums.size()==1) return nums[0];
	// if(nums.size()==2) return max(nums[0], nums[1]);
	int prevprev = nums[0];
	int prev = max(nums[0], nums[1]);

	for(int i = 2; i<nums.size(); i++){
		int temp = prevprev;
		prevprev = max(prev, prevprev);
		prev = max(temp+nums[i], prev);
	}
	return prev;

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    vector<int> vec;
    int input;
    while(cin>>input) vec.push_back(input);

    cout<<rob(vec);

	return 0;
}
