#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(Node next, int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* Insert(Node** head, int data){
    Node* temp = new Node();

    temp->data = data;

    temp->next = *head;

    *head = temp;
}

int binarySearch(int a[], int l, int r, int x){
    while(l <= r){
        int m = l + (r-l)/2;

        if(a[m] == x){
            return a[m];
        }
        else if(a[m] > x){
            l = m+1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}

int partition(vector<int> a, int l, int r){
    int i = l -1;
    int pivot = r;
    for(int j = 0 ; j < pivot; j++){
        if(a[j] < a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[pivot]);
    return i+1;
}
int quickSort(vector<int> a, int l, int r){
    if(l <= r){
        int pi = partition(a, l, r);

        quickSort(a, l, pi-1);
        quickSort(a, pi+1, r);
    }
}

int mergeSortIntervals(int a[], int l, int m, int r){
    vector<int> temp;
    int i = l;
    int j = m+1;
    while(i <= m && j <= r){
        if(a[i] < a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else if(a[j] < a[i]){
            temp.push_back(a[j]);
            j++;
        }
    }
    while(i <= m){
        temp.push_back(a[i]);
    }
    while(j <= r){
        temp.push_back(a[j]);
    } 
    for(int i = l; i < r; i++){
        a[i] = temp[i-l];
    }
}

void mergeSort(int a[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        mergeSortIntervals(a, l, m, r);
    }
}

int main(){

}