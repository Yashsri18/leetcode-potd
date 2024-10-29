class Solution {
public:
int n , m ;
int dp[1001][1001];
int solve(int i , int j ,vector<vector<int>>&grid){
    if(i>=n || j>=m)return 0 ;
    if(dp[i][j]!=-1)return dp[i][j];
    int opt1=0,opt2=0,opt3=0;
    if(i+1<n && j+1 <m && grid[i+1][j+1]>grid[i][j]){
        opt1=1+solve(i+1,j+1,grid);
    }
    if(i<n && j+1 <m && grid[i][j+1]>grid[i][j]){
        opt2=1+solve(i,j+1,grid);
    }
    if(i-1>=0 && j+1 <m && grid[i-1][j+1]>grid[i][j]){
        opt3=1+solve(i-1,j+1,grid);
    }
    return dp[i][j]=max({opt1,opt2,opt3});
}
    int maxMoves(vector<vector<int>>& grid) {
         n = grid.size(),m=grid[0].size();
        int ans= 0 ;
        memset(dp,-1,sizeof dp);
        for(int i = 0 ; i < n;i++){
            ans=max(ans,solve(i,0,grid));
        } 
    return ans;
    }
};