#include<iostream>
using namespace std;
#include<vector>

bool canJump(vector<int>& nums) {
    if(nums.size()<=1) return true;
    else if(nums[0]==0) return false;
    vector<bool> jumpable;
    int n = nums.size();
    jumpable.push_back(true);
    for(int i = 1; i<n; i++) jumpable.push_back(false);

    for(int i = 0; i<n; i++){
        // cout<<boolalpha<<i<<jumpable[i]<<endl;
        if(!jumpable[i]) return false;
        for(int j = i; j<i+nums[i]+1; j++){
            if(j==n-1) return true;
            else jumpable[j] = true;
        }
    }
    return true;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    vector<int> vec;
    int input;
    while(cin>>input){
    	vec.push_back(input);
    }

    cout << boolalpha << canJump(vec) << endl;

	return 0;
}
