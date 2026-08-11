class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        if( n == 1) return nums[0]+1 ;
        int ans = nums[0]+1;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        int l = 0, r = 1;
        int sublen = 0;
        int sum = nums[0];
        // while (r < n) {
        //         if (nums[r] == nums[r - 1] + 1) {
        //             int sublene = r - l + 1;
        //             sum += nums[r];
        //             if (sublene > sublen) {
        //                 sublen = sublene;
        //                 int temp = sum;
        //                 while (mpp.find(temp) != mpp.end()) {
        //                     temp++;
        //                 }
        //                 ans = temp;
        //             }
                 
        //         } else {
        //             while (l < r) {
        //                 sum -= nums[l];
        //                 l++;
        //             }
        //         }
        //            r++;
            
        // }
        while( r < n && nums[r] == nums[r-1]+1  ){
            sum += nums[r++];
            
        }
        int temp = sum;
                while (mpp.find(temp) != mpp.end()) {
                        temp++;
                        }
                      
                       ans = temp;
        
        return ans;
    }
};