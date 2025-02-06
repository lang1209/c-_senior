#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 * 4 + 5;
int n, m, s[N];
//数据记得开到4倍的数据范围 
int sum(int k,int l,int r,int x,int y){
	int ans = 0;
	//cout << k << " " << l << " " << r << " " << x << " " << y <<"\n";
	//getchar(); 
	//节点为k, 范围为[l,r] , 所求范围为[x,y]
	if( x <= l && r <= y){
		return s[k];
	} 
	int mid = (l + r) / 2;
	if(x <= mid){
		ans += sum(k * 2, l, mid, x, y);	
	}
	if(y > mid){
		ans += sum(k * 2 + 1, mid + 1, r, x, y);
	}
	return ans;
}

void add(int k,int l,int r,int p,int x){
	s[k] += x;
	if(l == r){
		return;
	}
	int mid = (l + r) / 2; 
	if(p <= mid){
		add(k * 2, l, mid, p, x);
	}else{
		add(k * 2 + 1,mid + 1, r, p, x);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		add(1, 1 ,n, i, x);
	}
	for(int i = 1; i <= m; i++){
		int op, x, y;
		cin >> op;
		if(op == 1){
			cin >> x >> y;
			add(1, 1, n, x, y);
		}else{
			cin >> x >> y;
			cout << sum(1 ,1, n, x, y) << "\n";
		}
	}
	return 0;
}
