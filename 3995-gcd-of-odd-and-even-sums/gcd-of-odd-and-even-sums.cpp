class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0 ; 
        int evenSum = 0 ; 
        int j = 1;
        for( int i = 0  ; i<n ; i++ ){
            oddSum += j++; 
            evenSum += j;
            j++;
        }

        int ans = 1 ;
        int temp = 2 ;  
        while( temp  <= min(oddSum , evenSum )){
            if(evenSum % temp == 0 && oddSum % temp == 0)
             ans = temp ; 
        temp++;
        }
        return ans ;

    }
};