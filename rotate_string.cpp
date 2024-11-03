class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        s+=s;
        int ans = s.find(goal);
        cout<<ans<<endl;
        return (ans!=-1)?true:false;
    }
};