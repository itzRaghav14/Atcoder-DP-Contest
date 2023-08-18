#include <bits/stdc++.h>
// #include "algo/debug.h"
using namespace std;

using ll = long long;

#define endl "\n"


void solve() {
	
	int n;
	cin >> n;
	
	vector<vector<int>> a(n, vector<int>(3));
	for(auto &x : a) for(auto &y : x) cin >> y;
	
	vector<vector<int>> dp(n, vector<int> (3 , 0));
	
	dp[0] = a[0];
	
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < 3; j++) {
			
			{
				int nxt = (j + 1) % 3;
				dp[i + 1][nxt] = max(dp[i + 1][nxt], dp[i][j] + a[i + 1][nxt]);
			}
			
			{
				int nxt = (j + 2) % 3;
				dp[i + 1][nxt] = max(dp[i + 1][nxt], dp[i][j] + a[i + 1][nxt]);
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < 3; i++) {
		ans = max(ans, dp[n - 1][i]);
	}
	
	cout << ans << endl;
	
}

int main() {
	
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("io/input.txt", "r", stdin);
    freopen("io/output.txt", "w", stdout);
    freopen("io/error.txt", "w", stderr);
    #endif
	
	int t = 1; 
	// cin >> t;
	
	while(t--) {
		solve();
	}
	
	return 0;
	
}
