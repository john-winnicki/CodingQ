#include<iostream>
using namespace std;
#include<vector> 

vector<int> productExceptSelf(vector<int>& nums) {
	int n = nums.size();

	if(n==0) return nums;

	vector<int> output(n, 1);
	int curr = nums[0];
	for(int i = 1; i<n; i++){
		output[i] = curr;
		curr *= nums[i];
	}
	curr = nums[n-1];
	// for(int i : output) cout<<i<<"  ";
	for(int i= n-2; i>=0; i--){
		output[i] *= curr;
		curr *= nums[i];
	}
	// cout<<endl;
	return output;
}


int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    vector<int> vec;
    int input;
    while(cin>>input) vec.push_back(input);

    vector<int> output = productExceptSelf(vec);

    for(int i : output) cout<<i<<"   ";

	return 0;
}
