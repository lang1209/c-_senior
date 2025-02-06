#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> tree[N];
int father[N], pos[N], sz[N], deepth[N];
int cnt;
int n, m, root; 
void dfs(int now, int fa){
	deepth[now] = deepth[fa] + 1;
	father[now] = fa;
	pos[now] = ++cnt;
	sz[now] = 1;
	for(auto s : tree[now]){
		if(s != fa){
			dfs(s, now);
			sz[now] += sz[s];
		}
	}
}
bool isAncestor(int p1, int p2){ // p1 是否为 p2 的祖先 
	return pos[p2] >= pos[p1] && pos[p2] <= pos[p1] + sz[p1] - 1; 
}
bool check(){
	int count;	
	cin >> count;
	int deepest = 0;
	vector<int> points(count);
	for(auto &i : points){
		cin >> i;
		if(i != root){
			i = father[i];
		}
		if(deepth[i] > deepth[deepest]){
			deepest = i;
		}
	}
	for(auto i : points){
		if(!isAncestor(i, deepest)){
			return false;
		}
	} 
	return true;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i < n; i++){
		int u,v;
		cin >> u >> v;
		if(i == 1){
			root = u;
		}
		tree[u].push_back(v);
		tree[v].push_back(u); 
	}
	dfs(root, 0);
	for(int i = 1; i <= m; i++){
		if(check()){
			cout << "YES\n";
		}else{
			cout <<"NO\n";
		}
	}
	return 0;
}
