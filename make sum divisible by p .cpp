class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int tsum=0;
        for(auto i : nums)tsum=(tsum%p+i%p)%p;
        
        int target=tsum%p;
        if(target==0)return 0 ;
        unordered_map<int,int>mp;
        mp[0]=-1;
    int j = 0, curr=0,ans=n;
    while(j<n){
        curr=(curr%p+nums[j]%p)%p;
        int rem=(curr-target+p)%p;
        if(mp.find(rem)!=mp.end()){
            ans=min(ans,j-mp[rem]);
        }
        mp[curr%p]=j;
        j++;
    }
return (ans==n)?-1: ans;
    }
};