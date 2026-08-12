class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mpp;
        int n = nums.size();
        int l = 0, r = 0;
        while (r < n) {

            mpp[nums[r]]++;

            while (mpp[nums[r]] > k) {
                mpp[nums[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};