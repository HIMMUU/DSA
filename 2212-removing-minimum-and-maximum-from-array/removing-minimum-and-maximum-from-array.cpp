class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minidx = -1 , maxidx = - 1; 
        int n = nums.size();
        int maxval = INT_MIN ; 
        int minval = INT_MAX; 

        for( int i = 0 ; i < n ; i ++){
            if( nums[i] > maxval  ){
                maxval = nums[i];
                maxidx = i;
            }
             if( nums[i] < minval ){
                minval = nums[i];
                minidx = i;
            }

        }
        
        int ans = 0 ; 
        int mid =n; 

    int a , b , c ; 
           a =  max( minidx , maxidx )+1 ; 
      b =  n - min( minidx , maxidx)  ;
        
        int c1 = min( minidx , maxidx ) +1 ;
        int c2 = n - max( minidx , maxidx );
        c = c1 + c2; 
         return min(a ,min(b,c) );

    }
};