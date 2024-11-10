class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int>one(32,0);
        int i = 0 ,j=0, ans=1e9;
        while(j<nums.size()){
            for(int k = 0 ; k < 32;k++)if(nums[j] & (1<<k))one[k]++;
            long num = 0 ;
            for(int k=0;k<32;k++)if(one[k])num+=(1<<k);
            while(num>=k && i<=j){
                ans=min(ans,j-i+1);
                for(int k = 0 ; k < 32;k++)if(nums[i] & (1<<k))one[k]--;
                long long newnum=0;
                 for(int k=0;k<32;k++)if(one[k])newnum+=(1<<k);
                 num=newnum;
                 i++;
            }
            j++;
        }
        return (ans==1e9)?-1:ans;
    }
};