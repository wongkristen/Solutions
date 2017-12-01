//
// Created by Kristen Wong on 10/25/17.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class IterativeInorderSolution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<TreeNode *> s;

        while (root != nullptr || !s.empty()) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            ans.push_back(root->val);
            root = root->right;
        }

        return ans;
    }
};