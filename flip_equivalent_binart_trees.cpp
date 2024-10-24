class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;
        
       
        bool noFlip = solve(p->left, q->left) && solve(p->right, q->right);
        bool flip = solve(p->left, q->right) && solve(p->right, q->left);
        
        return noFlip || flip;
    }

    bool flipEquiv(TreeNode* p, TreeNode* q) {
        return solve(p, q);
    }
};
