class Solution {
public:
void func(vector<int>& v1, int ind, int sum, vector<int>& v2, vector<vector<int>>& ans){
    if(sum == 0){
        ans.push_back(v2);
        return;
    }
    if(sum < 0){
        return;
    }
    if(ind < 0){
        return;
    }
    func(v1, ind - 1, sum, v2, ans);
    v2.push_back(v1[ind]);
    func(v1, ind, sum - v1[ind], v2, ans);
    v2.pop_back();
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        func(candidates, candidates.size() - 1, target, v, ans);
        return ans;
    }
};