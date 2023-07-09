/**
 * 给定一个二叉树，找出其最大深度。
    二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
    说明: 叶子节点是指没有子节点的节点。
    示例：
    给定二叉树 [3,9,20,null,null,15,7]，
        3
       / \
      9  20
        /  \
       15   7
    返回它的最大深度 3 。
    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
 */
#include <iostream>
#include <queue>

//  Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class Solution {
public:
    void createTree(TreeNode *head, int n) {
        if (n <= 0) {
            return;
        }
        TreeNode *lNode = new TreeNode(n--);
        TreeNode *rNode = new TreeNode(n--);
        head->left  = lNode;
        head->right = rNode;
        createTree(head->left, n);
        createTree(head->right, n);
    }
    //中序遍历
    void midViewNodes(TreeNode *head) {
        cout << head->val << endl;

        TreeNode *lNode = head->left;
        TreeNode *rNode = head->right;

        if (lNode != NULL) {
            midViewNodes(lNode);
        }
        if (rNode != NULL) {
            midViewNodes(rNode);
        }
    }
    //前序遍历
    int leftViewNodes(TreeNode *head) {
        static int count = 0;
        static int max_depth = 0;
        TreeNode *lNode = head->left;
        TreeNode *rNode = head->right;

        if (lNode != NULL) {
            count++;
            leftViewNodes(lNode);
        } else {
            max_depth = max(max_depth, count);
            cout << "depth" << max_depth << endl;
            count = 0;
        }

        cout << head->val << endl;

        if (rNode != NULL) {
            leftViewNodes(rNode);
        }
        return max_depth;
    }
    //后序遍历
    int rightViewNodes(TreeNode *head) {
        static int count = 0;
        static int max_depth = 0;
        TreeNode *lNode = head->left;
        TreeNode *rNode = head->right;

        if (rNode != NULL) {
            count++;
            rightViewNodes(rNode);
        } else {
            max_depth = max(max_depth, count);
            cout << "depth" << max_depth << endl;
            count = 0;
        }

        cout << head->val << endl;

        if (lNode != NULL) {
            rightViewNodes(lNode);
        }

        return max_depth;
    }
    int maxDepth(TreeNode* root) {
        int lDepth = leftViewNodes(root);
        int rDepth = rightViewNodes(root);
        cout << "lDepth" << lDepth << endl;
        cout << "rDepth" << rDepth << endl;
        return max(lDepth, rDepth);
    }
    //深度优先搜索算法
    int maxDepth2(TreeNode* root) {
        if (!root) {
            return 0;
        }

        TreeNode *lNode = root->left;
        TreeNode *rNode = root->right;
        int lDepth = maxDepth2(lNode);
        int rDepth = maxDepth2(rNode);
        return max(lDepth, rDepth) + 1;
    }

    //迭代的方法遍历,使用队列缓存节点
    int maxDepth3(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode *> que;
        que.push(root);
        int depth = 0;
        while (!que.empty()) {
            depth++;
            int num = que.size(); //获取当前队列的大小
            for (int i = 0; i < num; i++) {
                TreeNode *node = que.front(); //当前队列的元素都出栈
                que.pop();

                if (node->left != NULL) {    //队列中的元素的子节点入队中去
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    que.push(node->right);
                }
            }
        }
        return depth;
    }

};

int main() {
    std::cout << "Hello, World!" << std::endl;

    Solution solu;

    TreeNode *head = new TreeNode(0);

    solu.createTree(head, 3);
//    solu.midViewNodes(head);
//    solu.leftViewNodes(head);
//    solu.rightViewNodes(head);

//    cout << solu.maxDepth(head);
//    cout << solu.maxDepth2(head);
    cout << solu.maxDepth3(head);



    return 0;
}