#include<iostream>
using namespace std;
#include<vector>

int robi(vector<int>& nums, int start, int end){
	int prevprev = nums[start];
	int prev = max(prevprev, nums[start+1]);
	for(int i = start+2; i<=end; i++){
		int temp = prev;
		prev = max(prevprev+nums[i], prev);
		prevprev = temp;
	}
	return prev;
}

int rob(vector<int>& nums) {
	if(nums.size()==0) return 0;
	else if(nums.size()==1) return nums[0];
	else if(nums.size()==2) return max(nums[0], nums[1]);
	else return max(robi(nums, 0, nums.size()-2), robi(nums, 1, nums.size()-1));
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    vector<int> vec;
    int input;
    while(cin>>input) vec.push_back(input);

    cout<<rob(vec)<<endl;

	return 0;
}
