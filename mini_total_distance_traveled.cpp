class Solution {
public:
#define ll long long 
ll dp[101][101][101];
ll solve(vector<int>& robot, vector<vector<int>>& factory,int i , int j ){
    if(i>=robot.size())return 0 ;
    if(j>=factory.size())return 1e18;
    if(dp[i][j][factory[j][1]]!=-1)return dp[i][j][factory[j][1]];
    ll opt1=solve(robot,factory,i,j+1);
    ll opt2=1e18;
    if(factory[j][1]>0){
        factory[j][1]--;
        opt2=abs(robot[i]-factory[j][0])+solve(robot,factory,i+1,j);
        factory[j][1]++;
    }else{
        opt2=solve(robot,factory,i,j+1);
    }
    return dp[i][j][factory[j][1]]=min(opt1,opt2);
}
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        memset(dp,-1,sizeof dp);
        sort(robot.begin(),robot.end());
         sort(factory.begin(),factory.end());
        return solve(robot , factory,0,0);
    }
};