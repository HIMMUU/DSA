
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();

        // Step 1: store indices
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        vector<int> ans;

        // Step 2: process queries
        for (int q : queries) {
            int val = nums[q];
            auto &v = mpp[val];

            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            auto it = lower_bound(v.begin(), v.end(), q);
            int idx = it - v.begin();

            int left = v[(idx - 1 + v.size()) % v.size()];
            int right = v[(idx + 1) % v.size()];

            int d1 = abs(q - left);
            int d2 = abs(q - right);

            d1 = min(d1, n - d1);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1, d2));
        }

        return ans;
    }
};