class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    sort( nums.begin() , nums.end()); 
    int n= nums.size();
    for( int i = 0; i < nums.size() ; i++){
        int j = i+1 ; 
        if( j < n && nums[i] == nums[j] ){
            return true ;
        }

    }
    return false ;}
};