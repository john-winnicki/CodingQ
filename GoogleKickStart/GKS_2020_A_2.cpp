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

int solve(int N, int K, int P, vector<vi> plate_set){
	vector<vi> memo;
	F0R(i, N){
		vi arr(P, 0);
		memo.pb(arr);
	}
	F0R(i, P) memo[0][i] = plate_set[0][i];

	for(int i = 1; i<N; i++){
		for(int j = 0; j<P; j++){
			int maxval = max(plate_set[i][j], memo[i-1][j]);
			for(int k = 1; k<=j; k++){
				maxval = max(maxval, plate_set[i][j-k]+memo[i-1][k-1]);
			}
			memo[i][j] = maxval;
			// cout<<memo[i][j]<<" ";
		}
		// cout<<endl;
	}
	// cout<<endl<<endl;

	// F0R(i, N){
	// 	F0R(j, P){
	// 		cout<<memo[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return memo[N-1][P-1];
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("../IO/input.txt", "r", stdin);
	freopen("../IO/output.txt", "w", stdout);
	#endif

    int T;
    cin>>T;

    F0R(i, T){
    	int N, K, P;
    	cin>>N>>K>>P;
    	vector<vector<int>> plate_set;
    	F0R(j, N){
    		vi arr;
    		int input;
    		int sum = 0;
    		F0R(k, K){
    			cin>>input;
    			sum += input;
    			arr.pb(sum);
    		}
    		FOR(k, K, P) arr.pb(sum);
    		plate_set.pb(arr);
    	}
    	int res = solve(N,K,P,plate_set);
    	cout<<"Case #"<<i<<": "<<res<<endl;
    	// cout<<endl<<endl;
    }

	return 0;
}
