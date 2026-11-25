/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* node, TreeNode* node2){
        if(!node && !node2) return true;
        if(!node || !node2) return false;
        if(node->val!=node2->val) return false;
        return isSameTree(node->left,node2->left) && isSameTree(node->right,node2->right);
    }
    bool dfs(TreeNode* node, TreeNode* subRoot){
        if (!subRoot) {
            return true;
        }
        if (!node) {
            return false;
        }
        // if(node->val == subRoot->val){
        //     return 
        // }
        if (isSameTree(node, subRoot)) return true;
        return dfs(node->left,subRoot) || dfs(node->right, subRoot);
        // return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) {
            return true;
        }
        if (!root) {
            return false;
        }
        return dfs(root,subRoot);
    }
};
