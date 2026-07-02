class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        health = health - grid[0][0];
        if(health <= 0) return false;
        queue<pair<pair<int,int>, int>>q;
        q.push({{0,0}, health});
        vector<vector<int>>best(n, vector<int>(m, -1));
        best[0][0] = health;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int x = cur.first.first;
            int y = cur.first.second;
            int currHealth = cur.second;
            if(x == n - 1 && y == m - 1) return true;
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int newHealth = currHealth - grid[nx][ny];
                if(newHealth <= 0) continue;
                if(newHealth > best[nx][ny]){
                    best[nx][ny] = newHealth;
                    q.push({{nx, ny}, newHealth});
                }
            }
        } 
        return false;
    }
};