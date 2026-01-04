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
    int minDepth(TreeNode* root) {
        stack<pair<TreeNode*,int>>st;
        if(!root)return 0;
        st.push({root,1});
        int ans=INT_MAX;
        while(!st.empty()){
            auto [node,depth]=st.top();
            st.pop();
            if(!node->left&&!node->right){
                ans=min(ans,depth);
            }
            if(node->left)st.push({node->left,depth+1});
            if(node->right)st.push({node->right,depth+1});
        }
        return ans;
    }
};