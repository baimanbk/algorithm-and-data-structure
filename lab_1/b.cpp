#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,n) for(int i=0;i<n;i++)
int main(){
int n ; 
cin >> n ;
vector <int> v ;
stack <int> s ;
fr(i,n){
    int x; 
    cin >> x ;
    v.push_back(x);
}
fr(i,n) {
    while(!s.empty() and s.top()>v[i]){
        s.pop();
    } if(s.empty()){
        cout << -1 << " " ;
    } else {
        cout << s.top() <<" " ;
    }
    s.push(v[i]) ;
}
return 0 ;
}