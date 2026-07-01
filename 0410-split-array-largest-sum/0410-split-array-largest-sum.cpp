class Solution {
private:
int countPartitions(vector<int>& nums, int maxSum){
    int n = nums.size();
    int partitions = 1;
    long long subArrsum = 0;
    for(int i = 0; i < n; i++){
        if(subArrsum + nums[i] <= maxSum){
            subArrsum += nums[i];
        }
        else{
            partitions++;
            subArrsum = nums[i];
        }
    }
    return partitions;

}
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            int partitions = countPartitions(nums, mid);
            if(partitions > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
        
    }
};