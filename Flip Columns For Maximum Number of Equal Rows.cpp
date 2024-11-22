class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<string,int>mp;
        for(auto row : matrix){
            string rownature="";
            int firstval=row[0];
            for(int col =0;col<m;col++)rownature+=(row[col]==firstval)?"s":"b";
            mp[rownature]++;
        }
        int ans = 0 ;
        for(auto i : mp){
            ans=max(ans,i.second);
        }
        return ans;
        
    }
};