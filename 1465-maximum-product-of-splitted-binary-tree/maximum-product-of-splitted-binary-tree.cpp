class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long maxProd = 0;

    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subSum = root->val + leftSum + rightSum;
        maxProd = max(maxProd, subSum * (totalSum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return maxProd % MOD;
    }
};
