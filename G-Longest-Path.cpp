#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define dbg(...) ; 
#define debug(...) ; 
#define crndl ; 
#endif

int dfs (int node, vector<int> &dist, vector<int> adj[]) {
	
	if(dist[node] != -1) {
		return dist[node];
	}
	
	int dis = 0;
	
	for(auto it : adj[node]) {
		dis = max(dis, 1 + dfs(it, dist, adj));
	}
	
	return dist[node] = dis;
	
}

void solve() {
	
	int n, m;
	cin >> n >> m;
	
	vector<int> adj[n];
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
	}
	
	vector<int> dist(n, -1);
	
	for(int i = 0; i < n; i++) {
		dfs(i, dist, adj);
	}
	
	int ans = *max_element(dist.begin(), dist.end());
	
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
