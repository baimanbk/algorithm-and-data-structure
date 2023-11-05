#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,n) for(int i=0;i<n;i++)
int main(){
stack <char> s;
string str; 
cin >> str ;
fr(i,str.size()) {
    if(!s.empty()){
        if(s.top()==str[i]) {
            s.pop() ;
        } else {
            s.push(str[i]) ;
        }
    } else{
        s.push(str[i]) ;
    }
} if(!s.empty()) cout << "NO" ;
else cout << "YES" ;
}
