class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int edgesL = edges.size();
        int inDegree[102];
        memset(inDegree, 0, sizeof(inDegree));

        for (int i = 0; i < edgesL; i++) {
            inDegree[edges[i][1]]++;
        }

        int cnt = 0, ans;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                ans = (i);
                cnt++;
            }
        }

        return cnt > 1 ? -1 : ans;
    }
};