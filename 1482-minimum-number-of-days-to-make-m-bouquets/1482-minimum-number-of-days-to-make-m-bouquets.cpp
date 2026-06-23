class Solution {
private:
bool possible(vector<int>& nums, int day, int m, int k){
    int n = nums.size();
    int cnt = 0, nofb = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] <= day){
            cnt++;
        }
        else{
            nofb += (cnt / k);
            cnt = 0;
        }
    }
    nofb += (cnt / k);
    return nofb >= m;
}
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = 1ll * m * 1ll * k;
        if(val > n) return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini, high = maxi, ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
        
    }
};