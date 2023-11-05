#include <bits/stdc++.h>

using namespace std;

int partition(int v[], int l, int r){
  int i = l-1;
  int pivot = v[r];
  for(int j = l; j <= r; j++){
    if(v[j] < pivot){
      i++;
      swap(v[i],v[j]);
    }
  }
  swap(v[i+1], v[r]);
  return (i+1);
}

void quickSort(int v[], int l, int r){
  if(l < r){
    int pi = partition(v, l, r);
    quickSort(v, l, pi-1);
    quickSort(v, pi+1, r);
  }
}

int main(){
    int n,m;
    cin >> n >> m;
    int a[m][n];
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> a[j][i];
        }
    }
    for(int i = 0 ; i < m; i++){
        quickSort(a[i], 0, n-1);
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            cout << a[j][i] << " ";
        }
        cout << "\n";
    }
}
