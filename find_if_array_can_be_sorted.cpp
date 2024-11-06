class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int sb = __builtin_popcount(nums[0]); 
        int mini = nums[0], maxi = nums[0]; 
        int maxprev = INT_MIN;

        for (int i = 1; i < nums.size(); i++) {
            if (__builtin_popcount(nums[i]) == sb) {
               
                maxi = max(nums[i], maxi);
                mini = min(nums[i], mini);
            } else {
                
                if (maxprev > mini) return false;

             
                maxprev = maxi;
                maxi = nums[i], mini = nums[i];
                sb = __builtin_popcount(nums[i]);
            }
        }

    
        return mini >= maxprev;
    }
};