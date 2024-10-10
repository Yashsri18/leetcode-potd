class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        
        // Step 1: Build a stack of indices of elements in decreasing order
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }
        
        int ans = 0;
        
        // Step 2: Traverse the array from right to left and calculate the ramp
        for (int i = n - 1; i >= 0; i--) {
            // While stack is not empty and the current element nums[i] is greater than or equal to the element at st.top()
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                ans = max(ans, i - st.top());
                st.pop();  // Pop the top element since we found a valid ramp
            }
        }
        
        return ans;
    }
};
