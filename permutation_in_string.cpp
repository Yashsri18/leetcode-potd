class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<int>mp1(26,0),mp2(26,0);
        for(auto i : s1)mp1[i-'a']++;
        int i = 0,j=0,ans=0;
        while(j<s2.size()){
            mp2[s2[j]-'a']++;
            if(j-i+1==s1.size()){
                if(mp1==mp2)return 1 ;
                mp2[s2[i]-'a']--;
                i++;
            }
            j++;
        }
return ans;
    }
};