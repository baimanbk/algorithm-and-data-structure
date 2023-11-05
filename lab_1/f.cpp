#include <bits/stdc++.h>

using namespace std;

int primenumber(int& n){
    int num = 1;
    int cnt = 0;
    int i;
    while(cnt < n){
        num += 1;
        for(i = 2 ; i <= num; i++){
            if(num % i == 0){
                break;
            }
        }
        if(i == num){
            cnt += 1;
        }
    }
    return num;
}

int main(){
    int n;
    cin >> n;
    cout << primenumber(n);
}