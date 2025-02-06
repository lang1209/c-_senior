#include<bits/stdc++.h>
using namespace std;
const int N = 500000;
const int M = 20;
vector<int> tree[N];
int n,m,s;
int deepth[N],father[N];
int f[M][N]; // f[i][j] : Óëj¾àÀë2^iµÄ×æÏÈ 
void dfs(int now,int fa){
	f[0][now] = fa;
	father[now] = fa;
	deepth[now] = deepth[fa] + 1;
	for(auto son : tree[now]){
		if(son != fa)
			dfs(son , now);
	}
}
int lca(int x,int y){
	if(deepth[x] > deepth[y]){
		swap(x, y);
	}
	for(int i = M; i >= 0; i--){
		if(deepth[y] - (1<<i) >= deepth[x]){
			y = f[i][y];
		}
	}
	if(x == y){
		return x;
	}
	for(int i = M; i >= 0; i--){
		if(f[i][x] != f[i][y]){
			x = f[i][x];
			y = f[i][y];
		}
	}
	return father[x];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(s, 0);
	for(int i = 1; i < M; i++){
		for(int j = 1; j <= n; j++ ){
			f[i][j] = f[i-1][f[i-1][j]];
		}
	}
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
	return 0;
} 
