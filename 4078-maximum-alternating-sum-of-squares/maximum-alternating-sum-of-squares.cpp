class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;
        long long ans = 0;
        for( int i = 0 ; i < n ; i++){
            if( nums[i] < 0){
                nums[i] *= -1;
            }
        }
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        if (n == 1)
            return nums[0] * nums[0];
        while (l < r) {
            ans += nums[r] * nums[r];
            r--;
            ans -= nums[l] * nums[l];
            l++;
        }
        if (n % 2 == 1) {
            ans += nums[r] * nums[r];
        }
        return ans;
    }
};