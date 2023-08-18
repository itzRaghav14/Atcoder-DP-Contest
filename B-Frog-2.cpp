#include <bits/stdc++.h>
// #include "algo/debug.h"
using namespace std;

using ll = long long;

#define endl "\n"


void solve() {
	
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	const int NP = 1e9;
	
	vector<int> dp(n, NP);
	dp[0] = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= k; j++) {
			if(i + j >= n) break;
			dp[i + j] = min(dp[i + j], dp[i] + abs(a[i] - a[i + j]));
		}
	}
	
	cout << dp[n - 1] << endl;
	
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
