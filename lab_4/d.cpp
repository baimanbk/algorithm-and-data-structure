#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    int level;
    Node* left;
    Node* right;
    Node(int val, int lvl) : value(val), level(lvl), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value, int level, vector<int>& level_sums) {
    if (root == nullptr) {
        level_sums[level - 1] += value;
        return new Node(value, level);
    }

    if (value < root->value) {
        root->left = insert(root->left, value, level + 1, level_sums);
    } else {
        root->right = insert(root->right, value, level + 1, level_sums);
    }

    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> permutation(n);

    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }

    Node* root = nullptr;
    vector<int> level_sums(n,0);
    int max_level = 0;

    for (int i = 0; i < n; i++) {
        root = insert(root, permutation[i], 1, level_sums);
    }

    for (int i = 0; i < level_sums.size(); i++) {
        if(level_sums[i] != 0){
            max_level++;
        }
    }
    cout << max_level << '\n';
    for(int i = 0 ; i < level_sums.size(); i++){
        if(level_sums[i] != 0){
            cout << level_sums[i] << " ";
        }
    }
    return 0;
}
