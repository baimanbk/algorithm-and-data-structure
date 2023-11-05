#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data){
    Node* newNode = new Node();
    newNode ->data = data;
    newNode ->left = NULL;
    newNode ->right = NULL;
    return newNode;
}

Node* Insert(Node* root, int data){
    if(root == NULL){
        root = GetNewNode(data);
    }
    else if(data <= root ->data){
        root ->left = Insert(root->left, data);
    }
    else{
        root ->right = Insert(root->right, data);
    }
    return root;
}

bool Search(Node* root, string s){
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] == 'L'){
            if(root->left == NULL){
                return false;
            }
            root = root -> left;
        }
        else{
            if(root->right == NULL){
                return false;
            }
            root = root -> right;
        }
    }
    return true;
}

int main(){
    Node* root = NULL;
    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        root = Insert(root, x);
    }
    for(int i = 0 ; i < m ; i++){
        string s;
        cin >> s;
        if(Search(root, s)){
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
}