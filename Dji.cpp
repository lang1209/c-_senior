#include<bits/stdc++.h>
//#define int unsigned long long
using namespace std;
const int N = 1e5 + 5;
const int M = 2e5 + 5;
long long dis[N];
bool vis[N];
vector<pair<long long,long long>> e[M];

priority_queue<pair<long long,long long>, 
vector<pair<long long,long long>>, 
greater<pair<long long,long long>>> q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int n, m ,s;	
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
	}
	
	//init
	for(int i = 0; i <= n; i++){
		if(i != s){
			dis[i] = INT_MAX;
		}
		q.push({dis[i], i});
	}
	
	//Dji
	while(!q.empty()){
		long long mn_id = q.top().second;
		long long mn_dis = q.top().first;
		vis[mn_id] = true;
		q.pop();
		
		if(mn_id == 0){
			break;
		}
		
		for(auto p : e[mn_id]){
			int x = p.first;
			int w = p.second;
			if(mn_dis + w < dis[x] && !vis[x]){
				dis[x] = mn_dis + w;
				q.push({dis[x], x});
			}
		}
	}
	
	//output
	for(int i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
	return 0;
}
