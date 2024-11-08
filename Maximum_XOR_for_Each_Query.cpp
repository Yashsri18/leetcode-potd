
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int b) {
        int n = nums.size();
        int maxK = (1 << b) - 1; // Maximum value of k with b bits
        vector<int> ans(n);

        // Compute the XOR of all elements in the array
        int totalXOR = 0;
        for (int num : nums) {
            totalXOR ^= num;
        }

        // Calculate the result for each query from end to start
        for (int i = 0; i < n; ++i) {
            ans[i] = totalXOR ^ maxK; // XOR with maxK to get the maximum k
            totalXOR ^= nums[n - 1 - i]; // Remove the last element’s contribution for the next query
        }

        return ans;
    }
};
