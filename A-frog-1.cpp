#include <bits/stdc++.h>
// #include "algo/debug.h"
using namespace std;

using ll = long long;
#define endl "\n"

void solve() {
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	const int NP = 1e9;
	
	vector<int> dp(n, NP);
	dp[0] = 0;
	
	for(int i = 0; i < n; i++) {
		// one step
		if(i + 1 < n) {
			dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i] - a[i + 1]));
		}
		
		if(i + 2 < n) {
			dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i] - a[i + 2]));
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
