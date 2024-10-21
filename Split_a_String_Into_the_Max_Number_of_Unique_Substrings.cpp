// day 19 
class Solution {
public:
        unordered_set<string>st;
    int solve(string s ,int i ){
        if(i>=s.size())return 0 ;
        int ans =0;
        for(int ind = i;ind<s.size();ind++){
            string temp =s.substr(i,ind-i+1);
            if(st.find(temp)==st.end()){
                st.insert(temp);
                ans=max(ans,1+solve(s,ind+1));
                st.erase(temp);
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        return solve(s,0);
    }
};