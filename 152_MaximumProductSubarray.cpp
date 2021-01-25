#include<iostream>
using namespace std;
#include<vector>

int maxProduct(vector<int>& nums) {
    int maxmax = nums[0];
    int mini = nums[0];
    int maxi = nums[0];

    for(int j= 1; j<nums.size(); j++){
        int i = nums[j];
        if(i>0){
            int temp_mini = min(min(mini, i),mini*i);
            int temp_maxi = max(max(maxi, maxi*i), i);
            mini = temp_mini;
            maxi = temp_maxi;
            maxmax = max(maxi, maxmax);
        }
        else{
            int temp_mini = min(min(mini*i, maxi*i), i);
            int temp_maxi = max(max(mini*i, maxi*i), i);
            mini = temp_mini;
            maxi = temp_maxi;
            maxmax = max(maxi, maxmax);
        }

        // cout<<i<<"    "<<mini<<"    "<<maxi<<endl;
    }
    return maxmax;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> arr;
    int input;
    while(cin>>input){
        arr.push_back(input);
    }

    cout<<maxProduct(arr)<<endl;

    return 0;
}
