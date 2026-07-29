
class Solution {
    long long CAP;
    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        __int128 res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res >= CAP) return CAP;
        }
        return (long long)res;
    }
    long long countPerms(const array<int,26>& cnt) {
        int n = 0;
        for (int c : cnt) n += c;
        __int128 res = 1;
        for (int c = 0; c < 26; c++) {
            if (!cnt[c]) continue;
            res *= comb(n, cnt[c]);
            if (res >= CAP) return CAP;
            n -= cnt[c];
        }
        return (long long)res;
    }
public:
    string smallestPalindrome(string s, long long k) {
        array<int,26> full{}, half{};
        for (char ch : s) full[ch - 'a']++;

        string mid = "";
        for (int c = 0; c < 26; c++) {
            if (full[c] & 1) mid = string(1, 'a' + c);
            half[c] = full[c] / 2;
        }
        CAP = k;                     
        if (countPerms(half) < k) return "";
        int m = 0;
        for (int c : half) m += c;
        string left;
        left.reserve(m);
        for (int pos = 0; pos < m; pos++) {
            for (int c = 0; c < 26; c++) {
                if (!half[c]) continue;
                half[c]--;                       
                long long p = countPerms(half);
                if (p >= k) {                    
                    left += char('a' + c);
                    break;
                }
                k -= p;                         
                half[c]++;                       
            }
        }
        string right(left.rbegin(), left.rend());
        return left + mid + right;
    }
};