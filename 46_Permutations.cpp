#include<iostream>
using namespace std;
#include <vector>

void permuteUtil(vector<int>& nums, vector<vector<int>>& fin, int pos){
    if(pos==nums.size()){
        fin.push_back(vector<int>(nums));
        return;
    }
    for(int i = pos; i<nums.size(); i++){
        swap(nums[pos], nums[i]);
        permuteUtil(nums, fin, pos+1);
        swap(nums[pos], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> fin;
    permuteUtil(nums, fin, 0);
    return fin;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int len;
    cin >> len;

    int input;
    vector<int> vec;
    while(cin>>input) vec.push_back(input);

    vector<vector<int>> fin = permute(vec);

    for(vector<int> v : fin) cout << v[0] << "  " << v[1] << "    " << v[2] << endl;

	return 0;
}
