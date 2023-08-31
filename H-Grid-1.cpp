#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

const int MOD = 1e9 + 7;

void solve() {
	
	int n, m;
	cin >> n >> m;
	
	vector<string> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<vector<int>> dp(n, vector<int> (m, 0));
	dp[0][0] = 1;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			
			auto update = [&] (int x, int y) {
				if(a[x][y] == '#') return;
				dp[x][y] += dp[i][j];
				if(dp[x][y] >= MOD) dp[x][y] -= MOD;
			};
			
			if(i + 1 < n) {
				update(i + 1, j);
			}
			
			if(j + 1 < m) {
				update(i, j + 1);
			}
		}
	}
	
	cout << dp[n - 1][m - 1] << endl;
	
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
	
	for(int _t = 0; _t < t; _t++) {
		solve();
	}
	
	return 0;
}
