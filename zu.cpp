#include<bits/stdc++.h>
using namespace std;
const int N = 25;
long long dp[N][N];
bool isHo[N][N];
int dx[] = {0, -1, -2, -1, -2, 1, 2, 1, 2};
int dy[] = {0, -2, -1, 2, 1, 2, 1, -2, -1};
int n, m;
void init(){
	int x, y;
	cin >> x >> y;
	for(int i = 0; i < 9; i++){
		int tx = x + dx[i];
		int ty = y + dy[i];      
		if(tx >= 0 && tx < N && ty >= 0 && ty < N){
			isHo[tx][ty] = true;
		}
	}
} 
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	init();
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		if(isHo[i][0]){
			break;
		}
		dp[i][0] = 1;
	}
	for(int i = 1; i <= m; i++){
		if(isHo[0][i]){
			break;
		}
		dp[0][i] = 1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			//cout << isHo[i][j] << " "; 
			if(!isHo[i][j]){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
			//cout << dp[i][j];
		}
		//cout << "\n";
	}
//	for(int i = 0 ; i <= n; i++){
//		for(int j = 0 ; j <= m; j++){
//			cout << dp[i][j];
//		}
//		cout << "\n";
//	}
	cout << dp[n][m];
	return 0; 
}
