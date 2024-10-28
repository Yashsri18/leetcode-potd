class Solution {
public:
#define ll long long int 

    int longestSquareStreak(vector<int>& nums) {
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
         sort(nums.begin(), nums.end());
        unordered_map<ll,ll>mp;
        for(int i = 0 ; i < nums.size();i++){
            mp[nums[i]]=i;
        }
        vector<ll>dp(nums.size(),-1);
        for(int i = 0 ; i < nums.size();i++){
            if(mp.find((1LL)*nums[i]*nums[i])!=mp.end()){
                dp[i]=mp[nums[i]*nums[i]];
            }
        }
        for(auto i :nums)cout<<i<<" ";
        cout<<endl;
        for(auto i :dp)cout<<i<<" ";
        ll maxi = 0;
        int flag=1;
        for(int i = nums.size()-1;i>=0;i--){
            if(dp[i]==-1)continue;
            if(dp[i]>-1)flag=0;
            ll ans= (dp[dp[i]]==-1)?2:dp[dp[i]]+1;
            dp[i]=ans;
            maxi=max(maxi,dp[i]);
        }
        if(flag)return -1;
        return maxi;

    }
};