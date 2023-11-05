#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

int maxDepthDifference(TreeNode* root, int& result) {
    if (root == nullptr) return 0;

    int leftDepth = maxDepthDifference(root->left, result);
    int rightDepth = maxDepthDifference(root->right, result);

    result = max(result, leftDepth + rightDepth);

    return 1 + max(leftDepth, rightDepth);
}

int findMaxDistance(TreeNode* root) {
    int result = 0;
    maxDepthDifference(root, result);
    return result;
}

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }

    return root;
}

int main() {
    int N;
    cin >> N;
    TreeNode* root = nullptr;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int maxDistance = findMaxDistance(root);
    cout << maxDistance + 1 << endl;

    return 0;
}
