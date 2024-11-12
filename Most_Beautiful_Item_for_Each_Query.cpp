class Solution {
public:
map<int,int>mp;
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        //for(auto i :items)cout<<"["<<i[0]<<" "<<i[1]<<"], ";
        int maxi = 0;
        for(auto i: items){
            if(mp.find(i[0])!=mp.end()){
                mp[i[0]]=max(i[1],maxi);
                maxi=max(maxi,i[1]);
            }
            else{ mp[i[0]]=max(maxi,i[1]);
             maxi=max(maxi,i[1]);
            }
        }
            vector<int> ans;
        for(auto q : queries){
            auto it= mp.lower_bound(q);
            //if(it==mp.end()){ans.push_back(0);continue;}
            if(it!=mp.end()&& it->first==q)ans.push_back(it->second);
            else{
            if(it==mp.begin()){ans.push_back(0);continue;}
            it--;
             ans.push_back(it->second);
            }
        }
        return ans;
    }
}; 