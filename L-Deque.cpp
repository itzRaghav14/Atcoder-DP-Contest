#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

void solve() {
	
	int n;
	cin >> n;
	
	vector<int> points(n);
	for(int i = 0; i < n; i++) {
		cin >> points[i];
	}
	
	vector<vector<long long>> maxPoints(n, vector<long long> (n, 0));
	
	for(int left = n - 1; left >= 0; left--) {
		for(int right = left; right < n; right++) {
			
			if(left == right) {
				maxPoints[left][right] = points[left];
				continue;
			}
			
			long long pickLeft = points[left] - maxPoints[left + 1][right];
			long long pickRight = points[right] - maxPoints[left][right - 1];
			
			maxPoints[left][right] = max(pickLeft, pickRight);
			
		}
	}
	
	cout << maxPoints[0][n - 1] << endl;
	
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
