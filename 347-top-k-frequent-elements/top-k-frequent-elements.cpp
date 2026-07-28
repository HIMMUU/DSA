class Solution {
    typedef pair<int, int> P;

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int num : nums)
            mpp[num]++;

        priority_queue<P, vector<P>, greater<P>> minheap;
        for (auto& it : mpp) {
        
            minheap.push({ it.second,it.first });

            if (minheap.size() > k) {
                minheap.pop();
            }
        }
        vector<int> res;
        while (!minheap.empty()) {
            res.push_back(minheap.top().second);
            minheap.pop();
        }
        return res;
    }
};