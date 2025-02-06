#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, m, a[105], s;
bool f[25005];
int main()
{
	cin >> t;
	while (t--)
    {
        cin >> n;
        m = n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        memset(f, false, sizeof(f));
        f[0] = true;
        for(int i = 1; i <= n; i++){
            if(f[a[i]]){
                m--;
                continue;
            }
            for(int j = a[i]; j <= a[n]; j++){
                f[j] |= f[j - a[i]];
            }
        }
        cout << m << "\n";
	}
	return 0;
}
