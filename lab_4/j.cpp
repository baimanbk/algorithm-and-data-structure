#include <bits/stdc++.h>

using namespace std;

vector<int> v1;

void BinarySearch(vector<int> v, int l, int r){
    if(l <= r){
        int mid = l + (r-l)/2;
        v1.push_back(v[mid]);
        BinarySearch(v, l, mid-1);
        BinarySearch(v, mid+1, r);
    }
}


int main(){
    int n;
    cin >> n;
    int len = pow(2,n) - 1;
    vector<int> v(len);
    for(int i = 0 ; i < len; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    BinarySearch(v, 0, len-1);
    for(int i = 0 ; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
}