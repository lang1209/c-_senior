#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 2e5 + 10;
vector<int> e[M];
vector<int> path;
int dg[N], son[N];

void dfs(int now){
	while(son[now] < e[now].size()){
		son[now]++;
		dfs(e[now][son[now] - 1]);
	}
	path.push_back(now);
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		dg[u]++, dg[v]--;
	}
	//判断有无欧拉路径
	int start = 1;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(abs(dg[i]) >= 2){
			cout << "No\n";
			return 0;
		}
		if(dg[i] >= 1){
			start = i;
		}
		if(dg[i]){
			cnt++;
		}
		sort(e[i].begin(), e[i].end());
	}
	if(cnt > 2){
		cout << "No\n";
		return 0;
	}
	
	//若有，dfs寻找欧拉路径
	dfs(start);
	reverse(path.begin(), path.end());
	for(int i = 0; i < path.size(); i++){
		cout << path[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
