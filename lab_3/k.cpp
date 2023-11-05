#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> v1(n);
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> v1[i];
    }
    vector<long long> v(n+1,0);
    for(int i = 0 ; i < n; i++){
        v[i+1] = v[i] + v1[i]; 
    }
    int minlen = n;
    for(int i = 0 ; i < n ; i++){
        int left = i;
        int l = i+1, r = n;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(v[mid] - v[left] >= k){
                r = mid-1;
                minlen = min(minlen, mid - left);
            }
            else{
                l = mid + 1;
            }
        }
    }
    cout << minlen;
    
}