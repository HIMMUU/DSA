// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         int l = 0, r = 0;
//         int sum = 0;
//         int ans = INT_MAX;
//         while (r < n) {
//             sum += nums[r];

//             while (sum >= target) {
//                 sum -= nums[l];
//                 l++;
//                 if( sum >= target)
//                 ans = min(ans , r-l+1);
            
                
//             }
//             r++;
//         }
//         return (ans != INT_MAX) ? ans : 0;
//     }
// };
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0;
        int ans = INT_MAX;

        while (r < n) {
            sum += nums[r];

            while (sum >= target) {
                ans = min(ans, r - l + 1);

                sum -= nums[l];
                l++;
            }

            r++;
        }

        return (ans != INT_MAX) ? ans : 0;
    }
};