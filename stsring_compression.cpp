class Solution {
public:
    string compressedString(string s) {
        int n=s.size();
        string ans= "";
        for(int i = 0 ; i < s.size();i++){
            int count = 1 ;
            int ind=i;
            char ch =s[i];
            while(i<n-1 && s[i+1]==s[i] && count<9){
                count++;
                i++;
            }
            ans+=to_string(count)+ch;
            
            
        }
        return ans;
    }
};