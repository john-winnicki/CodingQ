#include<iostream>
using namespace std;
#include<vector>

int maxProfit(vector<int>& prices) {
    int mini = prices[0];
    // int maxi = prices[0];
    int maxmax = 0;
    for(int i = 1; i<prices.size(); i++){
        mini = min(mini, prices[i]);
        // maxi = max(maxi, prices[i]);
        maxmax = max(maxmax, prices[i]-mini);
    }
    return maxmax;
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

   	cout<< maxProfit(vec)<<endl;

	return 0;
}
