#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n;
vector<int> adj[N];
int dp[N][2];

void modadd (int &a, int b) {
	a += b;
	if(a >= MOD) a -= MOD;
}

void modmul (int &a, int b) {
	a = 1LL * a * b % MOD;
}

void dfs (int node, int par) {
	
	int &white = dp[node][0];
	int &black = dp[node][1];
	
	black = white = 1;
	
	for(auto child : adj[node]) {
		if(child == par) continue;
		dfs(child, node);
		modmul(white, dp[child][0] + dp[child][1]);
		modmul(black, dp[child][0]);
	}
	
}

void solve() {
	
	cin >> n;
	
	for(int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	dfs(1, 0);
	
	int ans = dp[1][0] + dp[1][1];
	if(ans >= MOD) ans -= MOD;
	
	cout << ans << endl;
	
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);
    freopen("io/error.txt", "w", stderr);
    #endif
	
	int t = 1;
	// cin >> t;
	
	for(int _t = 1; _t <= t; _t++) {
		debug(Testcase, _t);
		solve();
		crndl;
	}
	
	return 0;
}
