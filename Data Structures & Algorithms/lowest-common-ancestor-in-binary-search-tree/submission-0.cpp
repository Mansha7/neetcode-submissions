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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!p || !q || !root){
            return NULL;
        }
        if(root->val == p->val || root->val == q->val) return root;
        if(root->val>p->val && root->val>q->val){
            cout<<"left"<<endl;
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val<p->val && root->val<q->val){
            cout<<"right"<<endl;
            return lowestCommonAncestor(root->right,p,q);
        }
        else return root; // if they lie on opp sides, root is the lca
    }
};
