#include<bits/stdc++.h>
using namespace std;
const int N = 6e3+5;
vector<int> tree[N];
int r[N], dp[N][2];
void dfs(int now, int fa){
	dp[now][0] = 0;
	dp[now][1] = r[now];
	
	for(auto s : tree[now]){
		if(s == fa){
			continue;
		}
		dfs(s, now);
		
		dp[now][0] += max(dp[s][0], dp[s][1]);
		dp[now][1] += dp[s][0];
	}
}
int main(){
	int n, root = 1;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> r[i];
	}
	for(int i = 1; i < n; i++){
		int l, k;
		cin >> l >> k;
		tree[l].push_back(k);
		tree[k].push_back(l);
	}
	
	dfs(root, 0);
	cout << max(dp[root][0], dp[root][1]) << "\n";
	return 0;
}
