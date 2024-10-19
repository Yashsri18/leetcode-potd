// day17 
class Solution {
public:
string invert(string &s){
    for(int i = 0 ; i < s.size();i++){
        if(s[i]=='0')s[i]='1';
        else s[i]='0';
    }
    return s ;
}
    char findKthBit(int n, int k) {
        string prev ="0";
        string curr="";
        for(int i = 2;i<=n;i++){
            curr=prev+"1";
           
           // cout<<curr<<endl;
             prev=invert(prev);
          //   cout<<prev<<endl;
           //  cout<<prev<<endl;
            reverse(prev.begin(),prev.end());
            curr+=prev;
            prev=curr;
        }
        cout<<prev<<endl;
        return prev[k-1];
    }   
};