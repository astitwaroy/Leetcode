class Solution {
private:
int getdivision(vector<int>& nums, int target){
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += ceil((double)(nums[i]) / (double)target);
    }
    return sum;
}
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n > threshold) return -1;
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(getdivision(nums, mid) <= threshold){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};