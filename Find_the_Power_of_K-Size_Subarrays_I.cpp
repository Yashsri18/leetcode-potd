class Solution {
public:
bool is(vector<int>&temp){
    int val=temp[0];
    for(int i = 1 ; i<temp.size();i++){
        val++;
        if(temp[i]!=val)return 0;
    }
    return 1 ;
}
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        int n =nums.size();
        for(int i =0;i<n-k+1;i++){
            vector<int>temp;
            for(int j=i;j<i+k;j++){
                temp.push_back(nums[j]);
            }
            if(is(temp)){
                ans.push_back(temp[temp.size()-1]);
                temp.clear();
            }else ans.push_back(-1);
        }
        return ans;
    }

};