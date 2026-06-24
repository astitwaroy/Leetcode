class Solution {
private:
int countShips(vector<int>& nums, int capacity){
    int n = nums.size();
    int weight = 1;
    int afterWeight = 0;
    for(int i = 0; i <n ; i++){
        if(afterWeight + nums[i] <= capacity){
            afterWeight += nums[i];
        }
        else{
            weight++;
            afterWeight = nums[i];
        }

    }
    return weight;

}
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        if(days > n) return -1;
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            int count = countShips(weights, mid);
            if(count > days){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
        
    }
};