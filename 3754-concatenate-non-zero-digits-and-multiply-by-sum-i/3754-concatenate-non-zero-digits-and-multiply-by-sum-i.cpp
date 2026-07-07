class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long x = 0;
        int sum = 0;
        for(char it: s){
            if(it != '0'){
                int digit = it - '0';
                x = x * 10 + digit;
                sum += digit; 
            }
        }
        return x * sum;
    }
};