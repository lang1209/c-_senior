#include<bits/stdc++.h>
using namespace std;
const int N = 5005; 
const int M = 2e5 + 5;
int fa[N];
struct edge{
	int x, y, w;
}e[M];

bool cmp(edge e1, edge e2){
	return e1.w < e2.w;
}

int getRoot(int x){
	if(fa[x] == x) return x;
	return fa[x] = getRoot(fa[x]);
}

int main(){
	int n, m;
	cin >> n >> m;
	//input
	for(int i = 1; i <= m; i++){
		cin >> e[i].x >> e[i].y >> e[i].w;
	}
	
	//init
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	sort(e + 1, e + m + 1, cmp);
	
	//Real
	int cnt = 0, ans = 0;
	for(int i = 1; i <= m; i++){
		int x = e[i].x, y = e[i].y;
		int xPack = getRoot(x), yPack = getRoot(y);
		if(xPack == yPack){
			continue;
		}
		ans += e[i].w;
		cnt++;
		fa[yPack] = xPack;
	}
	if(cnt == n - 1){
		cout << ans << "\n";
	}else{
		cout << "orz\n";
	}
	
	return 0;
}
