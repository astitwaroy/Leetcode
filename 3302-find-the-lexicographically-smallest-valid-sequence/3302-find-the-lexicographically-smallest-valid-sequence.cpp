
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> late(m + 1);
        late[m] = n;
        int p = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (p >= 0 && word1[p] != word2[j]) --p;
            late[j] = p;
            if (p >= 0) --p;
        }
        vector<int> ans;
        ans.reserve(m);
        bool used = false;  
        int j = 0;
        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);           
                ++j;
            } else if (!used && late[j + 1] >= i + 1) {
                ans.push_back(i);           
                used = true;            
                ++j;
            }
        }
        return (j == m) ? ans : vector<int>();
    }
};
