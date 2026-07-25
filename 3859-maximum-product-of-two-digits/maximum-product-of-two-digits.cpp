class Solution {
public:
    int maxProduct(int n) {
        
        int n1 = 0 , n2 = 0; 

        while( n > 0 ){
        int  temp = n%10 ; 
            n /= 10 ;
            if( n1 < temp ){
                 if( n2 < n1 ){
                n2 = n1;
            }
                n1 = temp ; 
                continue ; 
            } 
            if( n2 < temp ){
                n2 = temp;
            }
        }
        return n1*n2;
    }
};