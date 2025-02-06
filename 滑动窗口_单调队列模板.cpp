#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
deque<int> qmax,qmin;

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        while(qmin.size() > 0 && a[i] < a[qmin.back()]){
            qmin.pop_back();
        }
        qmin.push_back(i);
        if(i - qmin.front() + 1 > k){
            qmin.pop_front();
        }
        if(i >= k){
            cout << a[qmin.front()] << " ";
        }
    }
    cout << "\n";
    for(int i = 1; i <= n; i++){
        while(qmax.size() > 0 && a[i] > a[qmax.back()]){
            qmax.pop_back();
        }
        qmax.push_back(i);
        if(i - qmax.front() + 1 > k){
            qmax.pop_front();
        }
        if(i >= k){
            cout << a[qmax.front()] << " ";
        }
    }
    cout << "\n";

    return 0;
}