#include<bits/stdc++.h>
using namespace std;
const int N = 1000000;
const int M = 21;
vector<int> tree[N];
//vector<int> treeA[N];
int deepth[N], father[N], path[M][N];
int pressure[N];
int ans = -1;
void dfs(int now, int fa){
	path[0][now] = fa;
	deepth[now] = deepth[fa] + 1;
	father[now] = fa;
	for(auto s : tree[now]){
		if(s == fa) continue;
		dfs(s, now);
		pressure[now] += pressure[s];
		//treeA[now] -= tree[s];
	}
	ans = max(ans, pressure[now]);
}
//void dfs_get(int now, int fa){
//	for(auto s : tree[now]){
//		if(s == fa) continue;
//		tree[now] = treeA[now] + treeA[fa];
//		ans = max(ans, tree[now]);
//		dfs(s, now);
//	}
//}
int lca(int x,int y){
	if(deepth[x] > deepth[y]){
		swap(x, y);
	}
	for(int i = M - 1; i >= 0; i--){
		if(deepth[y] - (1 << i) >= deepth[x]){
			y = path[i][y];
		}
	}
	if(x == y) return x;
	for(int i = M - 1; i >= 0; i--){
		if(path[i][x] != path[i][y]){
			x = path[i][x], y = path[i][y];
		}
	}
	return father[x];
}
int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(1, 0);
	for(int i = 1; i < M; i++){
		for(int j = 1; j <= n; j++ ){
			path[i][j] = path[i-1][path[i-1][j]];
			//cout << path[i][j] << " ";
		}
		//cout << "\n";
	}
	for(int i = 1; i <= k; i++){
		int s, t;
		cin >> s >> t;
		pressure[s]++, pressure[t]++;
		pressure[lca(s, t)]-- , pressure[father[lca(s, t)]]--;
		//cout<<"lca:"<<lca(s, t)<<"\n";
	}
//	cout << "-----\n"; 
//	for(int i = 0; i <= n; i++){
//		cout << pressure[i] << "\n";
//	}
 	dfs(1, 0);
	cout << ans;
	return 0;
}
