#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &v, int l, int r){
  int i = -1;
  int pivot = v[r];
  for(int j = l; j <= r; j++){
    if(v[j] < pivot){
      i++;
      swap(v[i],v[j]);
    }// 2, 5, 4   
  // -1 0  1  2 
    //  l     r   
    // i = 0;
    // j = 1;
    // 2, 5, 4
    // 0, 1, 2
    // 2, 4, 5
  }
  swap(v[i+1], v[r]);
  return (i+1);
}

void quickSort(vector<int> &v, int l, int r){
  if(l < r){
    int pi = partition(v, l, r);
    quickSort(v, l, pi-1);
    quickSort(v, pi+1, r);
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for(int i = 0 ; i < n ; i++){
    cin >> v[i];
  }
  vector<int> v1(m);
  for(int i = 0 ; i < m ; i++){
    cin >> v1[i];
  }
  quickSort(v, 0, n-1);
  quickSort(v1, 0, m-1);
  int i = 0;
  int j = 0;
  while(i < n && j < m){
    if(v[i] == v1[j]){
      cout << v[i] << " ";
      i++;
      j++;
    }
    else if(v[i] < v1[j]){
      i++;
    }
    else{
      j++;
    }
  }
}