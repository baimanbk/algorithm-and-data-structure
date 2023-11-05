#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        this->data = x;
        this->left = this->right = NULL;
    }
};

Node* Insert(Node* root, int x){
    if(root == NULL){
        root = new Node(x);
    }
    else if(root -> data <= x){
        root->left =  Insert(root->left, x);
    }
    else{
        root->right =  Insert(root->right, x);
    }
    return root;
}

int Count(Node* root,int cnt){
    if(root != NULL){
        if(root->left != NULL && root->right != NULL){
            cnt++;
        }
        cnt = Count(root->left, cnt);
        cnt = Count(root->right, cnt);
    }
    return cnt;
}

int main(){
    Node* root = NULL;
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        root = Insert(root, x);
    }
    cout << Count(root, 0);
}