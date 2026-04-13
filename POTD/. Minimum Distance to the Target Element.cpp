#include <iostream>
using namespace std;
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int high = nums.size() - 1;
        int low = 0 ;
        int min =0 ;
        while (low <= high ){
           int mid = low + (high - low) / 2;
            if(nums[mid] == target){

             min =  abs(mid - start);
            break;
            }
            else if(nums[mid]> target) 
            high = mid -1 ;
            else
             low = mid +1;
        }

return min;

    }
};