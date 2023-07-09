#include <iostream>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *createTree(int *arr, int len) {
        if (len <= 0) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(arr[0]);
        TreeNode *curNode = root;
        for (int i = 1; i < len; i++) {
            TreeNode *node = new TreeNode(arr[i]);

            while (curNode->val < arr[i] && curNode->left != NULL) {
                curNode = curNode->left;
            }
            while (curNode->val >= arr[i] && curNode->right != NULL) {
                curNode = curNode->right;
            }

            if (curNode->val < arr[i]) {
                curNode->left = node;
            } else {
                curNode->right = node;
            }
        };
        return root;
    }


    int kthSmallest(TreeNode* root, int k) {

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    int arr[] = {1, 3, 5, 4, 2, 9, 10, 6};
    Solution solu;
    TreeNode *root = solu.createTree(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}