#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int dp[N];
int main(){
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	dp[1] = 0;
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + 1;
		if(i % 2 == 0){
			dp[i] = dp[i/2] + 1;
		}
	}
	cout << dp[n] << "\n";
	
	return 0;
}
