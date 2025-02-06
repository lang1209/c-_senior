#include<bits/stdc++.h>
using namespace std;
const int N = 300; 
int dp_min[N][N], a[N], as[N];
int dp_max[N][N];
int n;
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i + n] = a[i];
		as[i] = as[i-1] + a[i];	
		//cout << as[i] << " ";
	}
	for(int i = n + 1; i <= 2 * n; i++){
		as[i] = as[i-1] + a[i];
	}
	//short to long
	for(int i = 1; i <= n * 2; i++){
		dp_min[i][i] = dp_max[i][i] = 0;
	}
	for(int l = 2; l <= 2 * n; l++){
		for(int i = 1; i <= n * 2; i++){
			int j = i + l - 1;
			if(j > 2 * n){
				continue;
			}
			dp_min[i][j] = INT_MAX;
			dp_max[i][j] = INT_MIN;
			for(int k = i; k < j;k++){
				dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k+1][j] + (as[j] - as[i - 1]));
				dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k+1][j] + (as[j] - as[i - 1]));
			}
		}
	}
	int ans_min = INT_MAX;
	int ans_max = INT_MIN;
	for(int i = 1; i <= n; i++){
		ans_min = min(ans_min,dp_min[i][i + n - 1]);
		ans_max = max(ans_max,dp_max[i][i + n - 1]);
	}
	cout << ans_min << "\n" << ans_max;
	return 0;
}
