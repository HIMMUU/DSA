
#include <iostream>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int max_dist = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int high = nums2.size() - 1;
            int low = i;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums1[i] <= nums2[mid]) {
                    max_dist = max(max_dist, mid - i);
                    low = mid + 1;
                } else if (nums1[i] > nums2[mid]) {
                    high = mid - 1;
                }
            }
        }

        return max_dist;
    }
};