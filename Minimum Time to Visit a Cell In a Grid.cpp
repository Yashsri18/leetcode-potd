class Solution {
    using node = pair<int, pair<int, int>>;

    const vector<pair<int, int>> DIR = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m {};
    int n {};

    bool in_bounds(int x, int y) {
        return 0 <= x && x <= m && 0 <= y && y <= n;
    }
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        m = grid.size() - 1;
        n = grid[0].size() - 1;

        vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size()));
        visited[0][0] = true;

        priority_queue<node, vector<node>, greater<node>> pq;
        pq.push({0, {0, 0}});

        int answer {};
        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();

            // cout << "[" << pos.first << ", " << pos.second << "] : " << value << endl;  

            if (pos.first == m && pos.second == n) {
                answer = time;
                break;
            }

            for (auto [dx, dy] : DIR) {
                int new_x {pos.first + dx};
                int new_y {pos.second + dy};

                if (in_bounds(new_x, new_y) && !visited[new_x][new_y]) {
                    int wait_time = ((grid[new_x][new_y] - time) % 2 == 0) ? 1 : 0;
                    int next_time = max(time + 1, grid[new_x][new_y] + wait_time);

                    visited[new_x][new_y] = true;
                    pq.push({next_time, {new_x, new_y}});
                }
            }
        }
        return answer;
    }
};