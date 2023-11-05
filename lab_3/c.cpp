#include <bits/stdc++.h>

using namespace std;

void PatchworkStaccatoI(int l1, int r1, int l2, int r2, vector<int> v){
    int cnt = 0;
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] >= l1 && v[i] <= r1 || v[i] >= l2 && v[i] <= r2){
            cnt++;
        } 
    }
    cout << cnt;
}

int main(){
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    while(q--){
        int l1,l2,r1,r2;
        cin >> l1 >> r1 >> l2 >> r2;
        PatchworkStaccatoI(l1,r1,l2,r2,v);
        cout << '\n';
    }
}