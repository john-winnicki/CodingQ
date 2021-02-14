#include<iostream>
using namespace std;
// #include <string>
// #include <unordered_map>
// #include <algorithm>
#include <vector>

int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size()-1;
    int max_area = 0;
    while(l<r){
        int min_height = min(height[l], height[r]);
        max_area = max(max_area, min_height*(r-l));
        if(height[l]<height[r]) l++;
        else r--;
    }
    return max_area;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    vector<int> heights;
    int input;
    while(cin >> input) heights.push_back(input);

    cout << maxArea(heights);

	return 0;
}
