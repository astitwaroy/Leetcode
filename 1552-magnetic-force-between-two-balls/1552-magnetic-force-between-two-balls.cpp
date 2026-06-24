class Solution {
private:
bool canPlace(vector<int>& nums, int dist, int cows){
    int n = nums.size();
    int cntCows = 1;
    int last = nums[0];
    for(int i = 1; i < n; i++){
        if(nums[i] - last >= dist){
            cntCows++;
            last = nums[i];
        }
        if(cntCows >= cows){
            return true;
        }
    }
    return false;
}
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1, high = position[n - 1] - position[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canPlace(position, mid, m) == true){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
};