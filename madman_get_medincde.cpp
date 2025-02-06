#include <iostream>
using namespace std;
const int N = 1e4+5;
int v[N], w[N], f[N];
int t, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	cin >> t >> m;
	for (int i = 1; i <= m; i++)
		cin >> v[i] >> w[i];
	for(int i = 1; i <= m; i++){
	    for(int j = v[i]; j <= t; j++){
	        f[j] = max(f[j], f[j - v[i]] + w[i]);
	    }
	}
	cout << f[t] << "\n";
	return 0;
}

