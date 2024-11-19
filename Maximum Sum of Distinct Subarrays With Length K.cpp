class Solution {
public:
#define ll long long
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll ans = 0, i = 0 ,j=0,sum=0;
        unordered_map<ll,ll>mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            sum+=nums[j];
            if(j-i+1==k){
                if(mp.size()==k){
                    ans=max(ans,sum);
                }
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};