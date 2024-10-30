class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans,dpf(n),dpb(n);
        ans.push_back(nums[0]);
        for(int i = 1 ; i < n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
                dpf[i]=ans.size()-1;
            }else{
                int pos=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[pos]=nums[i];
                dpf[i]=pos;
            }
        }
        ans.clear();
        ans.push_back(nums[n-1]);
        for(int i = n-2;i>=0;i--){
            if(ans.back()<nums[i]){
                ans.push_back(nums[i]);
                dpb[i]=ans.size()-1;
            }else{
                int pos=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[pos]=nums[i];
                dpb[i]=pos;
            }
        }
        int res=3;
        for(int i = 1 ; i < n-1;i++){
            if(dpf[i]!=0 && dpb[i]!=0)res=max(res,dpf[i]+dpb[i]+1);
        }
        return n - res;
    }
};

