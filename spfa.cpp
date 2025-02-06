#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 5e5 + 5;
vector<pair<int,int>> e[M];
int dis[N], cnt[N];
bool vis[N];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

int main(){
	int n, m, s;
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
	}
	for(int i = 0; i <= n; i++){
		if(i != s){
			dis[i] = 1e9;
		}
		q.push({dis[i], i});
	}
	
//	for(int t = 1; t <= n; t++){
//		for(int i = 1; i <= n; i++){
//			if(!vis[i]){
//				vis[i] = true;
//				for(auto j : e[i]){
//					int x = j.first;
//					int w = j.second;
//					if(dis[i] + w < dis[x]){
//						dis[x] = dis[i] + w;
//					}
//				}
//			}
//		}
//	}
	while(!q.empty()){
		int id = q.top().second;
		int d = q.top().first;
		q.pop();
		vis[id] = false;
		cnt[id]++;
		if(cnt[id] > 2 * n){
			cout << ((1 << 31) - 1) << "\n";
			return 0;
		}
		for(auto s : e[id]){
			int s_id = s.first;
			int s_w = s.second;
			if(d + s_w < dis[s_id]){
				dis[s_id] = d + s_w;
				if(!vis[s_id]){
					q.push({dis[s_id], s_id});
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
	
	return 0;
}
