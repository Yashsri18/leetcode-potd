class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()>s2.size())return areSentencesSimilar(s2,s1);
        vector<string>v1,v2;
        stringstream ss(s2);
        string word;
        while(ss>>word){
            v2.push_back(word);
        }
       
        stringstream s(s1);
        string w1;
        while(s>>w1){
           v1.push_back(w1);
        }
        int st = 0 , en= 0 ;
        int n = v1.size(),m=v2.size();
        while(st<n && v1[st]==v2[st])st++;
        while(en<n && v1[n-en-1]==v2[m-en-1])en++;
        if(st+en>=n)return 1 ;
        return 0 ;
    }
};