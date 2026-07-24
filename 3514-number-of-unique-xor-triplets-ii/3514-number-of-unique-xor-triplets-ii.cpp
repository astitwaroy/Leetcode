class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048; 
        vector<bool> pairXor(MAXX, false);
        vector<bool> ans(MAXX, false);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                pairXor[nums[i] ^ nums[j]] = true;
            }
        }
        for (int x : nums) ans[x] = true;
        for (int v = 0; v < MAXX; v++) {
            if (!pairXor[v]) continue;
            for (int x : nums) {
                ans[v ^ x] = true;
            }
        }
        int cnt = 0;
        for (bool b : ans) cnt += b;
        return cnt;
    }
};