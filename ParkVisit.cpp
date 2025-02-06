#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
vector<int> tree[N];
int l[N];
int ans = 0;
int root;
void dfs(int now,int fa){
	l[now] = 0;
	int mx = 0;
	for(auto i : tree[now]){
		if(i != fa){
			dfs(i, now);
			ans = max(ans, mx + l[i] + 1);
			mx = max(mx, l[i] + 1);
			l[now] = max(l[now], l[i] + 1);
		}
	}
}
int main(){
	cin.tie(0);
	cout.tie(0);
	int n, t, k;
	cin >> t >> n >> k;
		while(t--){
			for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			if(i == 1) root = u;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		dfs(root, 0);
		for(int i = 1; i <= k; i++){
			int cnt;
			cin >> cnt;
			cout << 2 * cnt - ans << "\n";
		}
	} 
	return 0;
}

