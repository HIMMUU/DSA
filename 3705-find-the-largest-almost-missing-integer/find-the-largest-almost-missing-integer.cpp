class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map < int , int > mpp ; 
        int n = nums.size() ; 
         int ans = -1; 
        if(  n == k ){
            for( int i =0 ;i < n ; i++){
                ans = max( ans ,nums[i]);
            }
            return ans ;
        }
        for(int i = 0 ; i < n ; i++ ){
            if(i+k <= n){
            for( int  j = i ; j < i+k ; j++ ){
                mpp[nums[j]]++;
            }}
        }
       
        for( auto it : mpp){
            if( it.second == 1)
            ans = max ( ans , it.first);
        }

        return ans ; 
    }
};