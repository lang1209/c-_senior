#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 21;
vector<int> tree[N];
int deepth[N], size[N];
int father[N]; 
int path[M][N]; 
int n,m;
void dfs(int now, int fa){
	father[now] = fa;
	path[0][now] = fa;
	deepth[now] = deepth[fa] + 1;
	for(auto son : tree[now]){
		if(son != fa){
			dfs(son, now);
			size[now] += size[son];
		}
	}
	if(tree[now].size() == 1){
		size[now] = 1;
	}
}
int lca(int x,int y){
	if(deepth[x] > deepth[y]){
		swap(x, y);
	}
	//跳到同一级 
	for(int i = M - 1; i >= 1; i--){
		if(deepth[y] - (1 << i) >= deepth[x]){
			y = path[i][y];
		}
	}
	//同步跳跃 
	for(int i = M - 1; i >= 1; i--){
		if(path[i][x] != path[i][y]){
			x = path[i][x];
			y = path[i][y];
		}
	}
	return father[x];
}
int e_p(int x,int y){
	int dis = deepth[x] + deepth[y] - 2 * deepth[lca(x, y)];
	if(dis % 2 == 0){
		return 0;
	}
	//从x开找
	if(deepth[x] < deepth[y]){
		swap(x, y);
	}
	int t = x;
	int k = dis / 2;
	for(int i = M - 1; i >= 1; i--){
		if(deepth[t] - (1 << i) >= deepth[x] - (dis / 2)){
			t = path[i][t];
			k -= (1 << i);
		}
	}
	int p = x;
	for(int i = M - 1; i >= 1; i--){
		if(deepth[p] - (1 << i) >= deepth[t] + 1){
			p = path[i][p];
		}
	}
	return (size[t] - size[p]);
} 
int main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u); 
	}
	dfs(1, 0);
	for(int i = M - 1; i >= 1; i--){
		for(int j = 1; j <= n; j++){
			path[i][j] = path[i-1][path[i-1][j]];
		}
	} 
	cin >> m;
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		cout << e_p(x, y) << "\n";
	}
	 
	return 0;
}
