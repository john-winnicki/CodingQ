#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using db = double; 
using str = string; // yay python!
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;
 
#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
tcT> using PR = pair<T,T>;
 
// pairs
#define mp make_pair
#define f first
#define s second
 
// vectors
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
 
// loops
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

void solve(int n, vi arr){
	int count[3] = {0};
	for(int i : arr) count[i%3]++;



	int max_ind = max_element(count, count+3)-count;
	// cout<<endl<<count[0]<<" "<<count[1]<<" "<<count[2]<<endl;
	int tot = 0;
	if(n/3-count[(max_ind+1)%3]<0) count[(max_ind+2)%3] += count[(max_ind+1)%3]-n/3;
	else tot += 

	int addnext = n/3-count[(max_ind+1)%3]+(n/3-count[(max_ind+2)%3])*2;

	

	// int min_ind = min_element(count, count+3)-count;

	// int mult = max_ind-min_ind;
	// if(mult<0) mult+=3;
	// cout<<mult<<endl;
	// cout<<(count[max_ind]-count[min_ind])*mult<<endl;
	
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
	#endif

    int t;
    cin>>t;
    F0R(i, t){
    	int n;
    	cin>>n;
    	int input;
    	vi arr;
    	F0R(j, n){
    		cin>>input;
    		arr.pb(input);
    	}
    	solve(n, arr);
    }

	return 0;
}
