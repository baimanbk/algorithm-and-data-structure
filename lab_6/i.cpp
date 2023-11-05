#include <bits/stdc++.h>

using namespace std;

int partition(string &s, int l, int r){
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

void quickSort(string &s, int l, int r){
  if(l < r){
    int pi = partition(s, l, r);
    quickSort(s, l, pi-1);
    quickSort(s, pi+1, r);
  }
}

int main(){
    string s;
    cin >> s;
    quickSort(s, 0, s.size()-1);
    cout << s;
}