class Solution {
public:
    int minChanges(string s) {
        int i =0,j=0,c1=0,c0=0,ans=0,n=s.size();
        while(j<s.size()){
            if(s[j]=='0')c0++;
            else c1++;
           if((j-i+1)%2==0){
                ans+=min(c0,c1);
                c1=0;
                c0=0;
           }
           j++;
        }
return ans;
    }
};

