class Solution {
public:
#define ll long long 
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long minval = LLONG_MAX;
        long long negcount = 0;
        long long sum = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] < 0) {
                    negcount++;
                }
                sum += abs(matrix[i][j]);
                minval = min(minval, (long long)abs(matrix[i][j]));
            }
        }

        if (negcount % 2 == 0) {
            return sum;
        }

        return sum - 2 * minval;
    }
};