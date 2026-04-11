#include <iostream>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;
        for (auto& it : mpp) {
            vector<int> indices = it.second;

            if (indices.size() >= 3) {
                int i = 0;
                int j = 1;
                int k = 2;

                while (k < indices.size()) {
                    int maxi = max(indices[i], max(indices[j], indices[k]));
                    int mini = min(indices[i], min(indices[j], indices[k]));

                    int dist = 2*(maxi - mini);
                     ans = min(ans, dist);
                    i++;
                    j++;
                    k++;
                }
            }
        }
        if(ans == INT_MAX ) return -1;
        return ans;
    }
};