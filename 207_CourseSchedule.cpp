#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>
#include<stack>
#include<unordered_map>

void topSort(int pos, vector<vector<int>>& prereqs, unordered_set<int>& seen, stack<int>& fin){
	seen.insert(pos);
	for(int i : prereqs[pos]){
		if(seen.find(i)==seen.end()){
			topSort(i, prereqs, seen, fin);
		}
	}
	fin.push(pos);
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> adj(numCourses, vector<int>());
	for(vector<int> i : prerequisites){
		adj[i[0]].push_back(i[1]);
	}

	unordered_set<int> seen;
	stack<int> mystack;

	for(int i = 0; i<numCourses; i++){
		if(seen.find(i)==seen.end()){
			topSort(i, adj, seen, mystack);
		}
	}

	unordered_map<int, int> hash;
	int index = 0;
	while(!mystack.empty()){
		hash[mystack.top()] = index;
		index++;
		mystack.pop();
	}

	for(int i = 0; i<numCourses; i++){
		for(int j : adj[i]){
			cout<< hash[i] << "     "<< hash[j]<<endl;
			// cout<<i<<"  "<<j<<endl;
			if(hash[j]<hash[i]) return false;
		}
	}
	return true;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int numCourses;
	cin>>numCourses;

    int pt1;
    int pt2;

    vector<vector<int>> prereqs;

    while(cin>>pt1){
    	cin>>pt2;
    	prereqs.push_back(vector<int>{pt1, pt2});
    }

    cout<<boolalpha<<canFinish(numCourses, prereqs);

	return 0;
}
