class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for(int i = 0 ; i < 31;i++){
            int count =0 ;
            for(auto j : candidates){
                if(j&(1<<i) )count++;
            }
            ans=max(ans,count);
        }
        return ans;
    }

};