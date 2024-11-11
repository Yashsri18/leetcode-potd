class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(),nums.end());
        
       set<int>st;
        vector<bool> sieve(maxElement + 1, true);
        sieve[1] =sieve[0] = false;
        for (int i = 2; i <= maxElement; i++) {
            if (sieve[i]) {
                st.insert(i);
                for (int j = i * i; j <= maxElement; j += i) {
                    sieve[j] = false;
                }
            }
        }
        int n =nums.size();
        for(int i = n-2;i>=0;i--){
            if(nums[i+1]>nums[i])continue;
            auto it = st.upper_bound(nums[i]-nums[i+1]);
            if(it==st.end())return 0 ;
            nums[i]-= *it;
            if(nums[i]<=0)return 0;  
        }
        return 1;
    }
};