#include<bits/stdc+++.h>
using namespace std;
const int N =
int n, m, s[N];

int getSum(int x){
	int res = 0;
	while(x){
		res += s[k];
		x -= x & (-x);
	}
	return res;
}

int add(int k, x){
	while(k <= n){
		s[k] += x;
		k += k & (-k);
	}
}

int main(){
	return 0;
}
