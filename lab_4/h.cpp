#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> prefsum(n);
    int sum = 0;
    for(int i = v.size()-1; i >= 0; i--){
        sum += v[i];
        prefsum[i] = sum;
    }
    for(int i = prefsum.size()-1; i >= 0 ; i--){
        cout << prefsum[i] << " ";
    }
}