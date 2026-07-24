class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long arrsum = 0;
        for (int i = 0; i < n; i++) { 
            sum += i;
            arrsum += nums[i]; }
            sum += n ; 
        return sum - arrsum;
    }
};