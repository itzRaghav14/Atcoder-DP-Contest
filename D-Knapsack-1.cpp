#include <bits/stdc++.h>
// #include "algo/debug.h"
using namespace std;

using ll = long long;

#define endl "\n"


void solve() {
	
	int n, wt;
	cin >> n >> wt;
	
	vector<vector<int>> a(n, vector<int> (2));
	for(int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	
	vector<vector<ll>> dp(n + 1, vector<ll> (wt + 1));
	
	auto ckmax = [&] (ll &a, ll b) {
		a = max(a, b);
	};
	
	for(int i = 0; i < n; i++) {
		for(int w = 0; w <= wt; w++) {
			
			{
				ckmax(dp[i + 1][w], dp[i][w]);
			}
			
			if(w + a[i][0] <= wt) {
				ckmax(dp[i + 1][w + a[i][0]], dp[i][w] + a[i][1]);
			}
		}
	}
	
	ll ans = 0;
	
	for(int i = 0; i <= wt; i++) {
		ckmax(ans, dp[n][i]);
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
