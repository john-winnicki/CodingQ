#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


bool replaceUtil(vector<int>& nums, int d){
	sort(nums.begin(), nums.end());
	if(nums.size()==0) return true;
	else if(nums.size()==1) return nums[0]<=d;
	else if(nums.size()==2) return nums[1]<=d;
	else{
		if(nums.back()<=d) return true;
		else return (nums[0]+nums[1])<=d;
	}
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int t;
    cin>>t;

	int input;
    for(int i = 0; i<t; i++){
    	int n, d;
    	cin>>n>>d;
    	vector<int> nums;
    	for(int i = 0; i<n; i++){
    		cin>>input;
    		nums.push_back(input);
    	}
    	cout<<(replaceUtil(nums, d) ? "YES" : "NO")<<endl;

    }

	return 0;
}
