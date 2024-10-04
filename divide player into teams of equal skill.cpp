class Solution {
public:
#define ll long long 
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        ll i = 0 , j=skill.size()-1;
        ll sum=skill[0]+skill[j],ans=0;
        while(i<j){//1 2 3 3 4 5
            if(skill[i]+skill[j]!=sum)return -1 ;
            ans+=(1LL*skill[i++]*skill[j--]);
        }
        return ans;
    }
};