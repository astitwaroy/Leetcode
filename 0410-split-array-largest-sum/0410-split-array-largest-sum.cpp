class Solution {
public:
    bool canSplit(vector<int>& nums, int maxSum, int k) {
        int currentSum = 0, splits = 1;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                splits++;
                currentSum = num;
                if (splits > k) return false; 
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int result = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, mid, k)) {
                result = mid; 
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }
        return result;
    }
};