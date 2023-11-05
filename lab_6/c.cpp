#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &v, int l, int r){
    int pivot = v[r];
    int i = l-1;
    for(int j = l ; j <= r; j++){
        if(v[j] < pivot){
            i++;
            swap(v[i], v[j]);
        }
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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n ; i++){
        cin >> v[i];
    }
    quickSort(v, 0, n-1);
    int min = INT_MAX;
    vector<int> v1;
    for(int i = 1; i < n ; i++){
        if(v[i] - v[i-1] < min){
            min = v[i] - v[i-1];
            v1.clear();
            v1.push_back(v[i-1]);
            v1.push_back(v[i]);
        }
        else if(v[i] - v[i-1] == min){
            v1.push_back(v[i-1]);
            v1.push_back(v[i]);
        }
    }
    for(int i = 0 ; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
}