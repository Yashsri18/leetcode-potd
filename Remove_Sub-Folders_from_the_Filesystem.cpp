class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        unordered_set<string>st;
        for(auto i : folder){
            string temp="";
            int flag=0;
            for(auto j : i){
                if(j=='/'){
                if(st.find(temp)!=st.end()){flag=1;break;}
                }
                temp+=j;
                
            }
            if(flag==0){
                st.insert(i);
            }
        }
        vector<string>ans;
        for(auto i : st){
            ans.push_back(i);
        }
        return ans;
    }
};