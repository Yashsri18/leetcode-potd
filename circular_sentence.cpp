class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string>s;
        stringstream ss(sentence);
        string word;
        while(ss>>word){
            s.push_back(word);
        }
int n =s.size();
        for(int i = 0 ; i < s.size() ;i++){
            if(!(s[i].back()==s[(i+1)%n][0]))return false;
        }
        return 1;
    }
};