class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = nums[0];
        vector<int> prefixgcd;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            int pgcd = __gcd(nums[i], maxi);
            prefixgcd.push_back(pgcd);
        }
        sort(prefixgcd.begin() , prefixgcd.end());
        int l  = 0 , r = prefixgcd.size()  -1 ; 
        long long ans = 0 ; 
        while( l <r){
           ans += __gcd( prefixgcd[l++],prefixgcd[r--]);
           
        }
        return ans;
    }
};