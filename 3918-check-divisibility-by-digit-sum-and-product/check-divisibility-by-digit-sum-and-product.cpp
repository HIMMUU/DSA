class Solution {
public:
    bool checkDivisibility(int n) {
     long long int sum =  0 ; 
        long long int product  = 1 ;
        int num = n ; 
        
        while( n > 0 ){
         int digi = n%10  ;
        n  = n /10 ; 
            sum += digi ; 
            product *= digi;
        } 
        if (num % (product+sum) == 0 ) return true; 
        else return false;  
    }
};