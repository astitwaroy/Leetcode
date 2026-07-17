class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx + 1);
        for (int x : nums) freq[x]++;
        vector<long long> exact(mx + 1);
        for (int i = 1; i <= mx; i++) {
            long long cnt = 0;
            for (int j = i; j <= mx; j += i)
                cnt += freq[j];

            exact[i] = cnt * (cnt - 1) / 2;
        }
        for (int i = mx; i >= 1; i--) {
            for (int j = i + i; j <= mx; j += i)
                exact[i] -= exact[j];
        }
        vector<long long> pref(mx + 1);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + exact[i];

        vector<int> ans;
        for (long long k : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), k + 1) - pref.begin();
            ans.push_back(g);
        }
        return ans;
    }
};