class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s = "123456789";
        for(int i = 2; i <= 9; i++){
            for(int j = 0; j + i <= 9; j++){
                int num = stoi(s.substr(j, i));
                if(num >= low && num <= high) ans.push_back(num);
            }
        }
        return ans;
    }
};