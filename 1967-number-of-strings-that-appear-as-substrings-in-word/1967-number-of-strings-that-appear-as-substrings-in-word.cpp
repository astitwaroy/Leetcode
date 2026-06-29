class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(auto it: patterns){
            if(word.find(it) != string::npos){
                count++;
            }
        }
        return count;
    }
};