#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 * 4;
int n, m;
long long s[N], tag[N];  //tag 懒标记
int L[N], R[N];	 
//注意!!!!!! : 这份代码只是写了大概，没有调试过 

void setTag(int k,int x){//设标记
	tag[k] += x;
	s[k] += (R[k] - L[k] + 1) * x;  
}

void pushUp(int k){ //将儿子算好的值给自己算 
	s[k] = s[k * 2] + s[k * 2 + 1];
}

void debug(int k,int l,int r,int t){
	if(l != r){
		int mid = (l + r) / 2;
		debug(k * 2, l, mid, t + tag[k]);
		debug(k * 2 + 1, mid + 1, r, t + tag[k]);
	}else{
		cout << s[k] + t << " ";
	}
}

void pushDown(int k){ // 向下传标记 
	setTag(k * 2, tag[k]);
	setTag(k * 2 + 1, tag[k]);
	tag[k] = 0;
} 

//数据记得开到4倍的数据范围 
int sum(int k,int l,int r,int x,int y){
	int ans = 0;
	//cout << k << " " << l << " " << r << " " << x << " " << y <<"\n";
	//getchar(); 
	//节点为k, 范围为[l,r] , 所求范围为[x,y]
	pushDown(k);
//	cout << "[DEBUG] ";
//	debug(k, l, r, tag[k]);
//	cout << "\n";
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

void add(int k,int l,int r,int x,int y,int v){
	if(x <= l && r <= y){
		setTag(k, v);
		return;
	}
	int mid = (l + r) / 2;
	pushDown(k);
	if(x <= mid){
		add(k * 2, l, mid, x, y, v);
	}
	if(y > mid){
		add(k * 2 + 1,mid + 1,r,x, y, v);
	}
	pushUp(k);
}

void build(int k,int l,int r){
	L[k] = l;
	R[k] = r;
	if(l != r){
		int mid = (l + r) / 2;
		build(k * 2, l , mid);
		build(k * 2 + 1, mid + 1, r);	
		pushUp(k);
	}else{
		cin >> s[k];
	} 
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
//	for(int i = 1; i <= n; i++){
//		int x;
//		cin >> x;
//		add(1, 1 ,n, i, i, x);
//	}
	build(1, 1, n);
//	cout << "[DEBUG] ";
//	debug(1, 1, n, 0);
//	cout << "\n";
	for(int i = 1; i <= m; i++){
		int op, x, y;
		cin >> op;
		if(op == 1){
			int k;
			cin >> x >> y >> k;
			add(1, 1, n, x, y, k); 
//			cout << "[DEBUG-ADD] ";
//			debug(1, 1, n, 0);
//			cout << "\n";
		}else{
			cin >> x >> y;
			cout << sum(1 ,1, n, x, y) << "\n";
//			cout << "[DEBUG-SUM] ";
//			debug(1, 1, n, 0);
//			cout << "\n";
		}
	}
	
	return 0;
}
