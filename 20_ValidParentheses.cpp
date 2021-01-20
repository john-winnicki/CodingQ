#include<iostream>
using namespace std;
#include <stack>

bool isValid(string s) {
    stack<char> Stack;
    for(char const &c : s){
        if(c=='(' || c=='[' || c=='{'){
            Stack.push(c);
            continue;
        }
        else if(Stack.size()==0) return false;
        else if(c==')'){
            if(Stack.top()!='(') return false;
        }
        else if(c==']'){
            if(Stack.top()!='[') return false;
        }
        else{
            if(Stack.top()!='{') return false;
        }
        Stack.pop();
    }
    return Stack.size()==0;        
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string str;
    getline(cin, str);

    cout << boolalpha << isValid(str);

    return 0;
}

