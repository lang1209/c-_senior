#include<bits/stdc++.h>
using namespace std;
const int N = 20000;
const int M = 100000;
vector<int> e[M];
int col[N];
bool flag;
bool vis[N];

void dfs(int now){
	vis[now] = true;
	for(auto s : e[now]){
		if(vis[s]){
			if(col[s] == col[now]){
				flag = true;
			}else{
				col[s] = 1 - col[now];
				dfs(s);
			}
		}
	}
}
