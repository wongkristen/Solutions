//
// Created by Kristen Wong on 10/9/17.
//

#include <iostream>
using namespace std;

class LongestUnivaluePathSolution {
    // Finds length of longest univalue path in a tree (the length of the path between 2 nodes is the number of edges between them).
//    EXAMPLE :     1
//              4       5
//          4       4       5       ANSWER = 2
public:
    int max;
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    int longestUnivaluePath(TreeNode* root) {
        max = 0;
        findExtensions(root);
        return max;
    }

    int findExtensions(TreeNode* root) {
        if(root == NULL) return 0;
        int left = findExtensions(root->left);
        int right = findExtensions(root->right);

        if (root->left != NULL && root->val == root->left->val) left++;
        else left = 0;

        if (root->right != NULL && root->val == root->right->val) right++;
        else right = 0;

        if (right + left > max) max = right + left;

        return (left > right ? left : right);
    }
};

