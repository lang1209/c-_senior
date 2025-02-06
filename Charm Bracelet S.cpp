#include<bits/stdc++.h>
using namespace std; //01 backpack
const int N = 12810;
const int M = 3410;
int dp[N];
int w[M], d[M]; //w 重量, d价值
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> w[i] >> d[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = m; j >= w[i]; j--){
			dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
		}
	}
	cout << dp[m] << "\n";
	return 0;
} 
