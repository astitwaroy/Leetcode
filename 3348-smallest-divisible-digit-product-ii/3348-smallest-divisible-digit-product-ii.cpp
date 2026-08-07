
class Solution {
    int V2[10] = {0,0,1,0,2,0,1,0,3,0};
    int V3[10] = {0,0,0,1,0,0,1,0,0,2};
    int V5[10] = {0,0,0,0,0,1,0,0,0,0};
    int V7[10] = {0,0,0,0,0,0,0,1,0,0};
    vector<vector<string>> dp; 
    static bool better(const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }
    void buildDp(int E2, int E3) {
        dp.assign(E2 + 1, vector<string>(E3 + 1, ""));
        for (int a = 0; a <= E2; a++)
            for (int b = 0; b <= E3; b++) {
                if (a == 0 && b == 0) continue;
                string best; bool has = false;
                for (int d : {2,3,4,6,8,9}) {
                    if ((a > 0 && V2[d] > 0) || (b > 0 && V3[d] > 0)) {
                        string cand = dp[max(0, a - V2[d])][max(0, b - V3[d])];
                        cand.push_back('0' + d);
                        sort(cand.begin(), cand.end());
                        if (!has || better(cand, best)) { best = cand; has = true; }
                    }
                }
                dp[a][b] = best;
            }
    }
public:
    string smallestNumber(string num, long long t) {
        long long tt = t;
        int e2=0,e3=0,e5=0,e7=0;
        while (tt % 2 == 0) { e2++; tt /= 2; }
        while (tt % 3 == 0) { e3++; tt /= 3; }
        while (tt % 5 == 0) { e5++; tt /= 5; }
        while (tt % 7 == 0) { e7++; tt /= 7; }
        if (tt != 1) return "-1";
        buildDp(e2, e3);
        int L = num.size();
        vector<array<int,4>> pref(L + 1, {0,0,0,0});
        int firstZero = L;
        for (int i = 0; i < L; i++) {
            int d = num[i] - '0';
            if (d == 0 && firstZero == L) firstZero = i;
            pref[i+1][0] = min(e2, pref[i][0] + V2[d]);
            pref[i+1][1] = min(e3, pref[i][1] + V3[d]);
            pref[i+1][2] = min(e5, pref[i][2] + V5[d]);
            pref[i+1][3] = min(e7, pref[i][3] + V7[d]);
        }
        if (firstZero == L && pref[L][0]==e2 && pref[L][1]==e3 && pref[L][2]==e5 && pref[L][3]==e7)
            return num;
        for (int i = min(L - 1, firstZero); i >= 0; i--) {
            int m = L - i - 1;
            for (int d = (num[i] - '0') + 1; d <= 9; d++) {
                int n2 = max(0, e2 - pref[i][0] - V2[d]);
                int n3 = max(0, e3 - pref[i][1] - V3[d]);
                int n5 = max(0, e5 - pref[i][2] - V5[d]);
                int n7 = max(0, e7 - pref[i][3] - V7[d]);
                const string& core = dp[n2][n3];
                int k = n5 + n7 + (int)core.size();
                if (k <= m) {
                    string tail = core + string(n5, '5') + string(n7, '7');
                    sort(tail.begin(), tail.end());
                    string res = num.substr(0, i);
                    res.push_back('0' + d);
                    res += string(m - k, '1');
                    res += tail;
                    return res;
                }
            }
        }
        const string& core = dp[e2][e3];
        int k = e5 + e7 + (int)core.size();
        int len = max(L + 1, k);
        string tail = core + string(e5, '5') + string(e7, '7');
        sort(tail.begin(), tail.end());
        return string(len - k, '1') + tail;
    }
};