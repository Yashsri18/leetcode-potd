//day 16
class Solution {
public:
int maxi = 0;
int count = 0 ;
void solve(int i , int curr, vector<int>&nums){
    if(curr==maxi){
        count++;
    }
    for(int j=i;j<nums.size();j++){
        int temp = curr;
        temp=temp|nums[j];
        solve(j+1,temp,nums);
        temp=curr;
    }
}
    int countMaxOrSubsets(vector<int>& nums) {
        for(auto i : nums)maxi=maxi|i;
        solve(0,0,nums);
        return count ;
    }
};