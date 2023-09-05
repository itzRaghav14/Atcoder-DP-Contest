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
	
	vector<int> height(n), value(n);
	vector<int> index(n + 1);
	for(int i = 0; i < n; i++) {
		cin >> height[i];
		index[height[i]] = i;
	}
	
	for(int i = 0; i < n; i++) {
		cin >> value[i];
	}
	
	map<int, long long> mp;
	long long ans = 0;
	
	auto findPrevVal = [&] (int x) -> long long {
		auto it = mp.lower_bound(x);
		if(it == mp.begin()) return 0;
		--it;
		return it->second;
	};
	
	for(int ht = 1; ht <= n; ht++) {
		int idx = index[ht];
		long long prev = findPrevVal(idx);
		long long val = prev + value[idx];
		while(!mp.empty()) {
			auto it = mp.lower_bound(idx);
			if(it == mp.end() || it->second > val) break;
			mp.erase(it);
		}
		mp[idx] = val;
		ans = max(ans, val);
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
	
	for(int _t = 1; _t <= t; _t++) {
		debug(Testcase, _t);
		solve();
		crndl;
	}
	
	return 0;
}
