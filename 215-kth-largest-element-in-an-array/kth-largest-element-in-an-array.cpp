class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxheap;
        for( int i = 0 ; i < nums.size() ; i++){
            maxheap.push(nums[i]);
        }
        for( int i = 0 ; i < k-1 ; i++){
            maxheap.pop();
        }
        return maxheap.top();
    }
};