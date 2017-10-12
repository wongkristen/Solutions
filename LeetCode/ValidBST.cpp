//
// Created by Kristen Wong on 10/12/17.
//

#include <iostream>
using namespace std;

class ValidBSTSolution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    bool isValidBST(TreeNode* root) {
        return traverse(root, NULL, NULL);
    }

    bool traverse(TreeNode* node, int max, int min) {
        if (node == nullptr) return true;

        if (node->left != nullptr && (node->left->val >= node->val || (min != NULL && node->left->val <= min))) return false;
        if (node->right != nullptr && (node->right->val <= node->val || (max != NULL && node->right->val >= max))) return false;

        return traverse(node->left, node->val, min) && traverse(node->right, max, node->val);

    }
};