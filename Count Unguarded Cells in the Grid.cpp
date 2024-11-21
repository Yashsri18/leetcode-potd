class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int v[m][n];
        memset(v,0,sizeof v);
        for(auto i : walls){
          //  st.insert(i);
            v[i[0]][i[1]]=2;// 2  means walls 
            }
            for(auto i : guards){
          //  st.insert(i);
            v[i[0]][i[1]]=3;// 3  means gaurd 
            }
        for(auto z:guards){
            int x = z[0],y=z[1];
            v[x][y]=1;
            int i =x-1,j=y;
            while(i>=0){
                if(v[i][j]==2 || v[i][j]==3)break;
                v[i][y]=1;
                i--;
            }
            i =x+1;
            while(i<m){
                if(v[i][j]==2 || v[i][j]==3)break;
                v[i][y]=1;
                i++;
            }
            i=x ;
            j = y-1;
            while(j>=0){
                if(v[i][j]==2 || v[i][j]==3)break;
                v[i][j]=1;
                j--;
            }
            j=y+1;
            while(j<n){
                if(v[i][j]==2 || v[i][j]==3)break;
                v[i][j]=1;
                j++;
            }
        }
        int ans= 0 ;
    for(int i = 0 ; i < m;i++){
        for(int j = 0 ; j < n;j++){
         //   cout<<v[i][j]<<" ";
            if(v[i][j]==0)ans++;
        }
        cout<<endl;
    }
    return ans;
    }
};