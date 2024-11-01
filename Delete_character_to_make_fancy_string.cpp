class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int i =0,j=0;
        while(j<s.size()){
            if(j>1){
                if(!(s[j-2]==s[j-1] && s[j-1]==s[j])){
                    ans+=s[j];
                }
            }else ans+=s[j];
            j++;
        }
        return ans;
    }
};