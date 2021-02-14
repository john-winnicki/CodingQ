#include<iostream>
using namespace std;
#include<vector>

int missingNumber(vector<int>& nums) {
	int sum = 0;
	for(int i : nums) sum += i;
	int tot = (nums.size())*(nums.size()+1)/2;
	return tot-sum;	
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> nums;
	int input;
	while(cin>>input) nums.push_back(input);

	cout<<missingNumber(nums)<<endl;    

	return 0;
}
