#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e6 * 4;
int n, m, q;
int s[N];  //tagÀÁ±ê¼Ç
int L[N], R[N];	 

struct Tag{
	int plus, tim;
	Tag operator + (Tag b){
		return{
			plus * b.tim + b.plus,
			tim * b.tim
		};
	}
} tag[N];

void setTag(int k,Tag x){
	tag[k] = tag[k] + x;
	s[k] = s[k] * x.tim + (R[k] - L[k] + 1) * x.plus;
}

void pushUp(int k){
	s[k] = s[k * 2] + s[k * 2 + 1];
}

void pushDown(int k){ 
	setTag(k * 2, tag[k]);
	setTag(k * 2 + 1, tag[k]);
	tag[k] = {1, 0};
} 

void debug(int k,int l,int r,Tag t){
	if(l != r){
		int mid = (l + r) / 2;
		debug(k * 2, l, mid, t + tag[k]);
		debug(k * 2 + 1, mid + 1, r, t + tag[k]);
	}else{
		cout << s[k] * t.tim + t.plus << " ";
	}
}

int sum(int k,int l,int r,int x,int y){
	long long ans = 0;
	//cout << k << " " << l << " " << r << " " << x << " " << y <<"\n";
	//getchar(); 
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
		setTag(k, {v, 1});
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

void mul(int k,int l,int r,int x,int y,int v){
	if(x <= l && r <= y){
		setTag(k,{0, v});
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

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	cin >> n >> q >> m;
//	for(int i = 1; i <= n; i++){
//		int x;
//		cin >> x;
//		add(1, 1 ,n, i, i, x);
//	}
	build(1, 1, n);
	cout << "[DEBUG-INPUT] ";
	debug(1, 1, n, {0, 1});
	cout << "\n";
	for(int i = 1; i <= q; i++){
		int op, x, y, k;
		cin >> op;
		if(op == 1){
			cin >> x >> y >> k;
			mul(1, 1, n, x, y, k); 
			cout << "[DEBUG-MUL] ";
			debug(1, 1, n, {k, 1});
			cout << "\n";
		}else if(op == 2){
			cin >> x >> y >> k;
			add(1, 1, n, x, y, k);
			cout << "[DEBUG-ADD] ";
			debug(1, 1, n, {0, k});
			cout << "\n";
		}else{
			cin >> x >> y;
			cout << sum(1, 1, n, x, y) << "\n";
		}
	}
	
	return 0;
}
