#include <bits/stdc++.h>

using namespace std;

int partition(vector<char> &s, int l, int r){
    int pivot = s[r] - '0';
    int i = l-1;
    for(int j = l ; j <= r; j++){
        if(s[j] - '0' < pivot){
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i+1], s[r]);
    return (i+1);
}

void quickSort(vector<char> &s, int l, int r){
  if(l < r){
    int pi = partition(s, l, r);
    quickSort(s, l, pi-1);
    quickSort(s, pi+1, r);
  }
}

int main(){
    int n;
    cin >> n;
    vector<char> s(n);
    for(int i = 0 ; i < n; i++){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    char c;
    cin >> c;
    for(int i = 0 ; i < n ; i++){
        if(c - '0' < s[i] - '0'){
            cout << s[i];
            return 0;
        }
    }
    cout << s[0];
}