class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k){

        vector<int> temp;
    int n = nums.size();
    int maxi = nums[0];
    int mini = INT_MAX;
    int ans = INT_MAX;
    int ansidx = INT_MAX;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, nums[i]);
        temp.push_back(maxi);
    }
    for (int i = n - 1; i >= 0; i--) {
        mini = min(mini, nums[i]);
        temp[i] -= mini;
    }
    for (int i = 0; i < n; i++) {
        if (temp[i] <= k) {
            ansidx = min(ansidx, i);
        }
    }
    return (ansidx == INT_MAX) ? -1 : ansidx;
}
}
;