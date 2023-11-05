#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,n) for(int i=0;i<n;i++)
int main(){
deque <int> nurs,vanya ; 
for (int i=0;i<5;i++) {
    int x ; 
    cin >> x ;
    vanya.push_back(x);
} for (int i=0;i<5;i++){
    int x ;
    cin >> x ;
    nurs.push_back(x) ; 
} int cnt = 0 ; 
while(!nurs.empty() and !vanya.empty() and cnt!=1000000){
    cnt++;
    if(vanya.front() == 0 and nurs.front() == 9) {
        vanya.push_back(vanya.front());
        vanya.push_back(nurs.front());
    } else if (vanya.front()==9 and nurs.front()==0) {
        nurs.push_back(vanya.front());
        nurs.push_back(nurs.front());
    } else if (vanya.front()>nurs.front()) {
        vanya.push_back(vanya.front());
        vanya.push_back(nurs.front());
    } else if (nurs.front()>vanya.front()) {
        nurs.push_back(vanya.front());
        nurs.push_back(nurs.front());
    }vanya.pop_front();
    nurs.pop_front();
}
if (vanya.empty()) {
    cout << "Nursik " << cnt ; 
} else if (nurs.empty()) {
    cout << "Boris " << cnt ;
} else cout << "blin nichya" ;
}

