class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mpp ; 
        int ans = 0 ; 
        int n = nums.size();
        if( n == 1 && nums[0] == k ) return k*2;
        for( int i = 0 ; i < nums.size(); i ++ ){
            if( nums[i] % k == 0 ){
                mpp[nums[i]]++;
            }
        }
        for(int i = 1 ; i <= nums.size()+1 ; i++){
            if(mpp.find(k*i) == mpp.end()){
                ans = k*i; 
                break;
            }
        }
        return ans;
    }
};