#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;

mt19937 R;

void solve(){
	int n;
	cin >>n;
	map<int,int> cnt,h,bla;
	vector<int> a(n), sum(n);
	for(auto &i : a){
		cin >> i;
		cnt[i]++;
	}
	for(int x = 0; x < n; x++){
		int i = a[x];
		if(cnt[i] > 1){
			sum[x] = R() % 100000000;
			h[i] += sum[x];
		}else{
			sum[i] = -h[i];
		}
		if(x > 0){
			sum[x] += sum[x-1];
		}
		cnt[i]--;
	}
	bla[0] = 1;
	int ans = 0;
	for(auto x : sum){
		ans += bla[x];
		bla[x]++;
	}
	cout << ans << "\n";
}

int main(){
	int _t = 1;
	cin >> _t;
	while(_t--){
		solve();
	}
	return 0;
}
