#include<bits/stdc++.h>
using namespace std;
const int N = 505;
vector<int> e[N];
queue<int> q;
int in[N];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		in[y]++;
	}
	for(int i = 1; i <= n; i++){
		if(in[i] == 0){
			q.push(i);
		}
	}
	while(q.size()){
		int x = q.front();
		q.pop();
		cout << x << " ";
		for(auto i : e[x]){
			in[i]--; 
			if(in[i] == 0){
				q.push(i);
			}
		}
	}
	return 0;
}
