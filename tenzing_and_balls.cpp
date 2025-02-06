#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int dp[N], a[N], mx[N]; 
int ans = INT_MIN;
int n, t;
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mx[i] = INT_MIN;
	}
	for(int i = 1; i <= n; i++){
		dp[i] = max(dp[i-1], i + 1 + mx[a[i]]);
		ans = max(dp[i], ans);
		mx[a[i]] = max(mx[a[i]], dp[i-1] - i);
	}
	//cout << "#";
	cout << dp[n] << "\n"; 
}
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
} 
