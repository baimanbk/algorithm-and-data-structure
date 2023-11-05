#include <bits/stdc++.h>

using namespace std;

int primeornot(int& n){
    for(int i = 2; i < n/2; i++){
        if(n % i == 0){
            return 0;
        }
        else continue;
    }
    return 1;
}


int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << "NO" << '\n';
        return 0;
    }
    if(primeornot(n)){
        cout << "YES" << '\n';
    }
    else cout << "NO" << '\n';
}