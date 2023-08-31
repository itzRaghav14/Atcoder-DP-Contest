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
	
	cout << fixed << setprecision(10);
	
	int n;
	cin >> n;
	
	vector<double> p(n);
	for(int i = 0; i < n; i++)
		cin >> p[i];
	
	
	vector<double> dp(n + 1, 0);
	dp[0] = 1;
	// dp[i] -> probability of having i heads 
	
	for(int i = 0; i < n; i++) {
		vector<double> ndp(n + 1, 0);
		for(int j = 0; j <= i; j++) {
			// heads
			{
				ndp[j + 1] += dp[j] * p[i];
			}
			// tails
			{
				ndp[j] += dp[j] * (1 - p[i]);
			}
		}
		dp = ndp;
	}
	
	double ans = 0;
	
	for(int i = (n +1) / 2; i <= n; i++) {
		ans += dp[i];
	}
	
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
	
	for(int _t = 0; _t < t; _t++) {
		solve();
	}
	
	return 0;
}
