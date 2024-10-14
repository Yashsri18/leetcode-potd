class Solution {
public:
#define ll long long 
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<ll>pq;
        ll ans = 0 ;
        for(auto i : nums)pq.push(i);
        for(ll i = 0 ; i < k ; i++){
            ll ele= pq.top();
            pq.pop();
            ans+=ele;
            pq.push(ceil(ele/3.0));
        }
        return ans;
    }
};