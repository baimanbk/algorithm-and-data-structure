#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* root, int data) {
    if (root == NULL) {
        return GetNewNode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root; 
}

Node* Search(Node* root, int target) {
    if (root == NULL || root->data == target) {
        return root;
    }
    if (target < root->data) {
        return Search(root->left, target);
    } else {
        return Search(root->right, target);
    }
}

void count(Node* root) {
    if (root == NULL) {
        return;
    }
    if(root){
        cout << root ->data << " ";
        count(root->left);
        count(root -> right);
    }
}

int main() {
    Node* root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = Insert(root, x);
    }
    int t;
    cin >> t;
    Node* current = Search(root, t);
    count(current);
    
    return 0;
}
