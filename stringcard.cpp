#include<bits/stdc++.h>
using namespace std;
const int N = 55;
string dp[N][N], s[N]; //dp[i][j] 后i个字符串，选择了j个 
bool cmp(string s1, string s2){
	return s1 + s2 < s2 + s1;
}
int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	sort(s + 1, s + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			dp[i][j] = "~";
		}
	}
	//dp[n][0]
	dp[0][0] = "";
	for(int i = n; i >= 1; i--){
		if (n==i){
            dp[i][1]=s[i];
            continue;
        }
		for(int j = 1; j <= k; j++){
			dp[i][j] = min(s[i]+dp[i+1][j-1],dp[i+1][j]);
		}
		
	}
	cout << dp[1][k] << "\n";
	return 0;
}
