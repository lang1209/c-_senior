#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], s[N];
struct person{
    int left;
	int right;
    int id;
    string job;
}p [N];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i].id = i;
        int dic;
        cin >> dic >> p[i].job;
        if(dic == 0){
            p[i].left = 1;
            p[i].right = -1;
        }else{
            p[i].left = -1;
            p[i].right = 1;
        }
    }
    for(int i = 1; i <= m; i++){
        cin >> a[i] >> s[i];
    }

    person target = p[1];
    for(int i = 1; i <= m; i++){
        int move = 0;
        if(a[i] == 0){
            move += p[i].left * s[i];
        }else{
            move += p[i].right * s[i];
        }
        if(target.id + move > 0){
            target = p[target.id + move];
        }else{
            target = p[target.id + (n - move + 1)];
        }
    }
    cout << target.job << "\n";
    return 0;
}
