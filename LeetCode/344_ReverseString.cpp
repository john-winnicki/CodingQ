#include<iostream>
using namespace std;
#include <vector>
#include <string>

void reverseString(vector<char> vec1) {
	int l = 0;
	int r = vec1.size()-1;
	cout << &vec1 << endl;
	while(l<r){
		char temp = vec1[l];
		vec1[l] = vec1[r];
		vec1[r] = temp;
		l++;
		r--;
	}
}

int main(){

	// std::cout << "C++ version: " << __cplusplus << std::endl;
	
	// cout <<"hi sir";

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif


	// cout<<"hi man 2";

	string s;

	cin >> s;

	// cout << &s;

	// cout << s << endl;

	vector<char> v(s.begin(), s.end());

	// cout << "hi man 1";

	// for(char c : v) cout << c;
	cout << &v << endl;

	reverseString(v);

	// cout << endl;

	// for(char c : v) cout << c;

	return 0;
}
