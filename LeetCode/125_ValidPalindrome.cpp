#include<iostream>
using namespace std;
#include<string>

bool isPalindrome(string s) {
    int l = 0;
    int r = s.length()-1;
    while(l<=r){
        if(!(isalpha(s[l])||isdigit(s[l]))) l++;
        else if(!(isalpha(s[r])||isdigit(s[r]))) r--;
        else if(tolower(s[l])!=tolower(s[r])) return false;
        else{
        	l++;
        	r--;
        }
    }
    return true;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string str;
    getline(cin, str);

    cout<<boolalpha<<isPalindrome(str);

	return 0;
}
