#include <bits/stdc++.h>
using namespace std;
vector<int> v;

bool isPrime(int n){
    if(n==0 || n==1){
        return false;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void calc(){
  
    for(int i=1;i<100000;i++){
        if(isPrime(i)){
            v.push_back(i);
        }
    }
}

int main()
{
    calc();   
    int n;
    cin>>n;
    cout<<v[v[n-1]-1];
    
}
