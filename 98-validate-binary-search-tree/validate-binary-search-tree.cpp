class Solution{
public:
    bool isValidBST(TreeNode*root){
        stack<TreeNode*>st;
        long long prev=LLONG_MIN;
        while(!st.empty()||root){
            while(root){
                st.push(root);
                root=root->left;
            }
            root=st.top();
            st.pop();
            if(root->val<=prev)
                return false;
            prev=root->val;
            root=root->right;
        }
        return true;
    }
};
