class Solution {
public:
    bool poss(int mid,int n,vector<int> &q){
        int count=0;
        for(int i=0;i<q.size();i++){
            int nums=q[i];
            count+=ceil((float)nums/mid);
        }
        if(count<=n){
            return true;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(poss(mid,n,quantities)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};