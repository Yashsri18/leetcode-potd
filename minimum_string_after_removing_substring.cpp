class Solution {
public:
    int minLength(string s) {
        while(s.find("AB")!=string::npos || s.find("CD")!=string::npos){
            cout<<s;
            if(s.find("AB")!=string::npos)s.erase(s.find("AB"),2);
            else if(s.find("CD")!=string::npos)s.erase(s.find("CD"),2);
        }
        return s.size();
    }
};