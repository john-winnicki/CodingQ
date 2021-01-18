#include<iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hash;
    for(int i : nums){
        if(hash.find(i)==hash.end()) hash[i] = 1;
        else hash[i]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(auto it : hash){
        // cout<<it.first << "    " << it.second << endl;
        pq.push(make_pair(it.second, it.first));
        if(pq.size()>k) pq.pop();
    }

    vector<int> fin;
    // cout << "here";
    while(!pq.empty()){
        // cout << pq.top().second << endl;
        fin.push_back(pq.top().second);
        pq.pop();
    }
    return fin;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

    int k;
    cin >> k;

    int input;
    vector<int> vec;
    while(cin>>input) vec.push_back(input);

    vector<int> fin = topKFrequent(vec, k);

    for(int i : fin) cout<< i << "   ";
    
	return 0;
}
