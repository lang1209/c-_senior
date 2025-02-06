#include<bits/stdc++.h>
using namespace std;
const int N = 20005;
const int M = 100005;
vector<pair<int,int>> e[M];
int col[N];
int limit, n ,m;
bool flag;
bool vis[N];

void dfs(int now){ //dfs_method
	vis[now] = true;
	for(auto s : e[now]){
		int x = s.first;
		int c = s.second;
		if(c <= limit){
			continue;
		}
		if(vis[x]){
			if(col[x] == col[now]){
				flag = true;
			}					
		}else{
			col[x] = 1 - col[now];
			dfs(x);
		}
	}
}

bool check(int x){
	//init
	for(int i = 1; i <= n; i++){
		vis[i] = false;
		col[i] = 0;
	}
	flag = false;
	limit = x;
	//dfs
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	return !flag;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	//int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){  //input
		int u, v, c;
		cin >> u >> v >> c;
		e[u].push_back({v, c});
		e[v].push_back({u, c}); 
	}
	
	int l = 0, r = 1e9 + 5, ans = 1e9 + 5;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout << ans << "\n";
}
