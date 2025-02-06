#include<bits/stdc++.h>
using namespace std;
const int N = 505;
vector<int> e[N];
queue<int> q;
int in[N];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x = -1;
		while(true){
			cin >> x;
			if(x == 0){
				break;
			}
			e[i].push_back(x);
			in[x]++;
		}
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
