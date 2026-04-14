#include <iostream>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int zeros = 0;
        int maxlen = INT_MIN;
         while (r < n) {
            if (nums[r] == 0) {
                zeros++;
            }

            // shrink only when invalid
            while (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);

            r++;
        }
        return maxlen;
    }
};