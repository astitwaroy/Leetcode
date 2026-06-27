class Solution {
    void helper(int idx, int n, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        if (idx == n) {
            ans.push_back(temp);
            return;
        }
        helper(idx + 1, n, nums, temp, ans);
        temp.push_back(nums[idx]);
        helper(idx + 1, n, nums, temp, ans);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, n, nums, temp, ans);
        return ans;
    }
};
