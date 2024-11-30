class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> inDeg, outDeg;
        unordered_map<int, vector<int>> graph;

        for(auto pair : pairs){
            graph[pair[0]].push_back(pair[1]);
            outDeg[pair[0]]++;
            inDeg[pair[1]]++;
        }

        int start = pairs[0][0];
        for(auto pair : pairs){
            int key = pair[0];
            if(outDeg[key] > inDeg[key]){
                start = key;
                break;
            }
        }
        
        stack<int> currStk;
        vector<int> path;
        currStk.push(start);
        path.push_back(start);
        while(!currStk.empty()){
            int curr = currStk.top();
            if(graph[curr].empty()){
                currStk.pop();
                path.push_back(curr);
            }else{
                int next = graph[curr].back();
                graph[curr].pop_back();
                currStk.push(next);
            }
        }


        vector<vector<int>> res;
        for(int i = path.size() - 1; i>=2; --i){
            res.push_back({path[i], path[i-1]});
        }

        return res;
    }
};