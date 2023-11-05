#include <bits/stdc++.h>

using namespace std;

void royalflush(int& n){
    deque<int> a;
    a.push_front(n);
    for(int i = n-1; i > 0 ; i--){
        a.push_front(i);
        for(int j = 0 ; j < i; j++){
            int d = a.back();
            a.push_front(d);
            a.pop_back();
    }   }
    while(!a.empty()){
        cout << a.front() << " ";
        a.pop_front();
    }
    cout << '\n';
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        royalflush(n);
    }
}