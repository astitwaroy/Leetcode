class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int mod = 1e9 + 7;
        vector<vector<int>>score(n, vector<int>(n, -1));
        vector<vector<int>>ways(n, vector<int>(n, 0));
        score[0][0] = 0;
        ways[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X') continue;
                if(i == 0 && j == 0) continue;
                int best = -1;
                if(i > 0) best = max(best, score[i - 1][j]);
                if(j > 0) best = max(best, score[i][j - 1]);
                if(i > 0 && j > 0) best = max(best, score[i - 1][j - 1]);
                if(best == -1) continue;
                int val = 0;
                 if(board[i][j] >= '1' && board[i][j] <= '9')
                    val = board[i][j] - '0';

                score[i][j] = best + val;

                if(i > 0 && score[i-1][j] == best)
                    ways[i][j] = (ways[i][j] + ways[i-1][j]) % mod;

                if(j > 0 && score[i][j-1] == best)
                    ways[i][j] = (ways[i][j] + ways[i][j-1]) % mod;

                if(i > 0 && j > 0 && score[i-1][j-1] == best)
                    ways[i][j] = (ways[i][j] + ways[i-1][j-1]) % mod;
            }
        }
        if(ways[n-1][n-1] == 0) return {0,0};
        return {score[n-1][n-1], ways[n-1][n-1]};
    }
};