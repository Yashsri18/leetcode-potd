// day 18
class Solution {
public:
char eval(string s ){
    int n= s.size();
    if(s[0]=='|'){
        int ans= 0;
        for(int i = 1 ; i < n;i++){
            if(isalpha(s[i])){
                char x = s[i];
                if(x=='t'){ans=1;break;}
            }
        }
        if(ans==1)return 't';
        else return 'f';
    }
    if(s[0]=='&'){
        int ans= 1;
        for(int i = 1 ; i < n;i++){
            if(isalpha(s[i])){
                char x = s[i];
                if(x=='f'){ans=0;break;}
            }
        }
        if(ans==1)return 't';
        else return 'f';
    }
    if(s[0]=='!'){
        if(s[1]=='t')return 'f';
        return 't';
    }
    return 'a';
}
    bool parseBoolExpr(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        stack<char>st;
        for(int i = 0; i < s.size();i++){
            if(s[i]!=')')st.push(s[i]);
            else{
                string temp = "";
                while(st.top()!='('){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                temp=st.top()+temp;
                st.pop();
                cout<<temp<<endl;
                char x =eval(temp);
                st.push(x);
            }
        }
        cout<<st.top();
        return st.top()=='f'?0:1;
    }
};