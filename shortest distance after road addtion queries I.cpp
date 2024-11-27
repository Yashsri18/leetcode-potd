class Solution {
public:
    int bfs(int n,unordered_map<int,vector<int>>&adj){
        queue<int>q;
        q.push(0);
        vector<bool>vis(n,false);
        vis[0]=true;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int node=q.front();
                q.pop();
                if(node==n-1) return level;
                for(int &nbr:adj[node]){
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr]=true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        vector<int>res;
        for(int i=0;i<=n-2;i++){
            adj[i].push_back(i+1);
        }
        int q=queries.size();
        for(auto &query:queries){
            int u=query[0];
            int v=query[1];

            adj[u].push_back(v);
            int d=bfs(n,adj);
            res.push_back(d);
        }
        return res;
    }
};