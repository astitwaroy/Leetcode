class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> segStart, segEnd, segType, segLen;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            segStart.push_back(i);
            segEnd.push_back(j - 1);
            segType.push_back(s[i] - '0');
            segLen.push_back(j - i);
            i = j;
        }
        int m = segStart.size();
        int totalOnes = 0;
        for (char c : s) if (c == '1') totalOnes++;
        vector<long long> gainStatic(m, 0);
        for (int k = 0; k < m; k++)
            if (segType[k] == 1 && k - 1 >= 0 && k + 1 < m)
                gainStatic[k] = (long long)segLen[k - 1] + segLen[k + 1];
        int LOG = 1;
        while ((1 << LOG) < m) LOG++;
        vector<vector<long long>> sp(LOG + 1, vector<long long>(max(m, 1), 0));
        for (int idx = 0; idx < m; idx++) sp[0][idx] = gainStatic[idx];
        for (int k = 1; k <= LOG; k++)
            for (int idx = 0; idx + (1 << k) <= m; idx++)
                sp[k][idx] = max(sp[k - 1][idx], sp[k - 1][idx + (1 << (k - 1))]);
        vector<int> logTable(m + 1, 0);
        for (int x = 2; x <= m; x++) logTable[x] = logTable[x / 2] + 1;
        auto rangeMax = [&](int l, int r) -> long long {
            if (l > r || m == 0) return 0;
            int k = logTable[r - l + 1];
            return max(sp[k][l], sp[k][r - (1 << k) + 1]);
        };
        auto findSeg = [&](int pos) -> int {
            int lo = 0, hi = m - 1, ans = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (segStart[mid] <= pos) { ans = mid; lo = mid + 1; }
                else hi = mid - 1;
            }
            return ans;
        };
        vector<int> res;
        res.reserve(queries.size());
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int segL = findSeg(l), segR = findSeg(r);
            long long candidateMax = 0;
            if (segR - segL >= 2) {
                int i1 = segL + 1, i2 = segR - 1;
                auto candidate = [&](int idx) -> long long {
                    if (segType[idx] != 1) return 0;
                    long long leftLen, rightLen;
                    leftLen  = (idx - 1 == segL) ? (segStart[idx] - l) : segLen[idx - 1];
                    rightLen = (idx + 1 == segR) ? (r - segEnd[idx])   : segLen[idx + 1];
                    return leftLen + rightLen;
                };
                candidateMax = max(candidateMax, candidate(i1));
                if (i2 != i1) candidateMax = max(candidateMax, candidate(i2));
                if (i1 + 1 <= i2 - 1)
                    candidateMax = max(candidateMax, rangeMax(i1 + 1, i2 - 1));
            }
            res.push_back(totalOnes + (int)candidateMax);
        }
        return res;
    }
};