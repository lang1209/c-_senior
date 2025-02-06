#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 25;
int point_w[N];
vector<int> e[N];
int deepth[N], father[N];
int bit[M][N];
int sum[N];

void dfs(int now,int fa){
	deepth[now] = deepth[fa] + 1;
	father[now] = fa;
	bit[0][now] = fa;
	sum[now] = e[now].size() + sum[fa];
	//cout << now << ":" << sum[now] << "\n";
	for(auto s : e[now]){
		if(s == fa){
			continue;
		}
		dfs(s, now);
	}
}

int lca(int x,int y){
	if(deepth[x] > deepth[y]){
		swap(x, y);
	}
	for(int i = M - 1; i >= 0; i--){
		if(deepth[y] - (1<<i) >= deepth[x]){
			y = bit[i][y];
		}
	}
	if(x == y){
		return x;
	}
	for(int i = M - 1; i >= 0; i--){
		if(bit[i][x] != bit[i][y]){
			x = bit[i][x];
			y = bit[i][y];
		}
	}
	return father[x];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i < n; i++){
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i < M; i++){
		for(int j = 1; j <= n; j++ ){
			bit[i][j] = bit[i-1][bit[i-1][j]];
		}
	}
	
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		//cout <<"[DEBUG]lca:" << lca(u, v) << "\n";
		cout << sum[u] + sum[v] - sum[lca(u, v)] - sum[father[lca(u, v)]] << "\n";
	}
	
    return 0;
}
