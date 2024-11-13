class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long  ans = 0;
        for(int i =  0; i < nums.size()-1;i++){
            int ele = nums[i];
            long long  lo=lower_bound(nums.begin()+i+1,nums.end(),lower-ele)-nums.begin();
            long long  hi=upper_bound(nums.begin()+i+1,nums.end(),upper-ele)-nums.begin();
            ans+=hi-lo;
        }
        return ans;
    }
};