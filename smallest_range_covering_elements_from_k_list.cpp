class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int maxi=-1e9;
        for(int i = 0 ; i < k;i++){
            pq.push({nums[i][0],i,0});
            maxi=max(maxi,nums[i][0]);
        }
        vector<int>range={-1000000,1000000};
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int mini=curr[0];
            int listIdx=curr[1];
            int idx=curr[2];
            if(maxi-mini<range[1]-range[0]){
                range[0]=mini;
                range[1]=maxi;
            }
            if(idx+1<nums[listIdx].size()){
                int nextele=nums[listIdx][idx+1];
                pq.push({nextele,listIdx,idx+1});
                maxi=max(maxi,nextele);
            }else break;
        }
    return range;
    }
};