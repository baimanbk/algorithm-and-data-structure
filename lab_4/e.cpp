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

Node* Search(Node* root, int x){
    if(root == NULL){
        return NULL;
    }
    if(root ->data == x){
        return root;
    }
    Node *found = Search(root->left, x);
    if (found == NULL)
    found = Search(root->right, x);
    return found;
}

int GetHeight(Node *root){
    if(root == NULL){
        return 0;
    }
    int lHeight = GetHeight(root->left);
    int rHeight = GetHeight(root->right);
    return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
}

int getWidth (Node *root, int level) {
    if (root == NULL)
        return 0;
    if (level == 1)
        return 1;
    else {
        return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
    }
}

int getMaxWidth (Node *root) {
    int max = 0, width;
    int h = GetHeight(root);
    for (int i = 1; i <= h; i++) {
        width = getWidth(root, i);
        if (width > max)
            max = width;
    }
    return max;
}

int main(){
    Node* root = NULL;
    Node* current;
    int n;
    cin >> n;
    for(int i = 0 ; i < n-1; i++){
        int x,y,z;
        cin >> x >> y >> z;
        if(root == NULL){
            current = new Node(x);
            root = current;
        }
        else{
            current = Search(root, x);
        }
        Node* tmp = new Node(y);
        if(z == 0){
            current -> left = tmp;
        }
        else{
            current->right = tmp;
        }
    }
    cout << getMaxWidth(root);
}