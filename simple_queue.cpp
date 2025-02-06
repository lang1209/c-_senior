#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
deque<int> q;
int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		//q.push_back(a[i]);
		//cout << "main loop\n";
		while(q.size() > 0 && a[i] > a[q.back()]){
			q.pop_back();
			//cout << "loop 1\n";
		}
		q.push_back(i);
		while(q.size() > k){
			q.pop_front();
		}
		
		if(i >= 3){
			cout << a[q.front()] << " ";
		}
	}
	return 0;
} 
