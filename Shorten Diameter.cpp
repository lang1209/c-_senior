#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, k, cnt, lim, ans = INT_MAX;
vector<int> tree[N];
int deepth[N];
int x[N], y[N];
void dfs(int now, int fa, int dep){
	if(dep > lim){
		return;
	}
	cnt++;
	for(auto i : tree[now]){
		if(i != fa){
			dfs(i, now, dep + 1);
		}
	}
}
int main(){
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		cin >> x[i] >> y[i];
		tree[x[i]].push_back(x[i]);
		tree[y[i]].push_back(y[i]);
	}
	for(int i = 1; i < n; i++){
		if(k % 2 == 1){
			lim = (k + 2) / 2;
			cnt = 0;
			//cout << "lim:" << lim << "\n";
			dfs(x[i], y[i], 1);
			dfs(y[i], x[i], 1);
			ans = min(ans,n - cnt);
		}else{
			lim = (k + 2) / 2;
			cnt = 0;
			dfs(x[i], 0, 1);
			ans = min(ans,n - cnt);
		}
	}
	cout << ans;
	return 0;
}
