class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>comp(n);
        int id = 0;
        comp[0] = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] > maxDiff){
                id++;
            }
            comp[i] = id;
        }
        vector<bool>ans;
        for(auto& it: queries){
            int u = it[0];
            int v = it[1];
            ans.push_back(comp[u] == comp[v]);
        }
        return ans;
    }
};