#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 20;
vector<pair<int, int>> tree[N];
int n,m,s;
int deepth[N],father[N],dis[N];
int f[M][N]; 
void dfs(int now,int fa){
	f[0][now] = fa;
	father[now] = fa;
	deepth[now] = deepth[fa] + 1;
	for(auto item : tree[now]){
		int son = item.first;
		int weight = item.second;
		if(son != fa){
			dis[son] = dis[now] + weight;
			dfs(son , now);
		}
	}
}
int lca(int x,int y){
	if(deepth[x] > deepth[y]){
		swap(x, y);
	}
	for(int i = M - 1; i >= 0; i--){
		if(deepth[y] - (1<<i) >= deepth[x]){
			y = f[i][y];
		}
	}
	if(x == y){
		return x;
	}
	for(int i = M - 1; i >= 0; i--){
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
	cin >> n >> m;
	int root;
	for(int i = 1; i < n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		if(i == 1){
			root = u;
		}
		tree[u].push_back({v,w});
		tree[v].push_back({u,w});
	}
	dfs(root, 0);
	for(int i = 1; i < M; i++){
		for(int j = 1; j <= n; j++ ){
			f[i][j] = f[i-1][f[i-1][j]];
		}
	}
	for(int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		cout << dis[a] + dis[b] - 2 * dis[lca(a, b)]<< "\n"; 
	}
	return 0;
} 
