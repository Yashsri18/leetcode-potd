class Solution {
public:
#define ll long long
    long long kthLargestLevelSum(TreeNode* root, int k) {
        ll ans = 0 ;
        queue<TreeNode*>q;
        q.push(root);
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        while(!q.empty()){
            ll n=q.size();
            ll sum = 0 ;
            for(int i = 0 ; i < n ; i++){
                auto node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            pq.push(sum);
            if(pq.size()>k)pq.pop();
        }
        return (pq.size()<k)?-1:pq.top();
    }
};