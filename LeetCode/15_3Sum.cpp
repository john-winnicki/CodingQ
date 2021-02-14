#include<iostream>
using namespace std;
#include <vector>


vector<vector<int>> threeSum(vector<int>& nums, int len) {
    sort(nums.begin(), nums.end());
    // for(int i = 0; i<len; i++) cout << nums[i] << "   ";
    vector<vector<int>> fin;
    // cout << endl;
    for(int i = 0; i<len-2; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int target = -1*nums[i];
        int l = i+1;
        int r = len-1;
        while(l<r){
            // cout << nums[i] << "   " << nums[l] << "   " <<nums[r] << endl;
            int res = nums[l] + nums[r];
            if(target==res){
                vector<int> guy;
                guy.push_back(nums[i]);
                guy.push_back(nums[l]);
                guy.push_back(nums[r]);
                fin.push_back(guy);
                l++;
                r--;
                while(l<r && nums[l]==nums[l-1]) l++;
                while(l<r && nums[r]==nums[r+1]) r--;
            }
            else if(target>res) l++;
            else r--;
        }
    }
    return fin;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	int len;
    cin >> len;

	vector<int> arr(len);
    for(int i = 0; i<len; i++) cin >> arr[i];

	vector<vector<int>> fin = threeSum(arr, len);


    for(vector<int> vec : fin) cout<< vec[0] << "    " << vec[1] << "      " << vec[2] << endl;


	return 0;
}
