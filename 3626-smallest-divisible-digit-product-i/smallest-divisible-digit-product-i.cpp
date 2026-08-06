class Solution {
public:
    int smallestNumber(int n, int t) {
        int product_digit = 1;
        int temp = n;
        while (temp > 0) {
            product_digit *= temp % 10;
            temp /= 10;
        }

        while (product_digit % t != 0) {
            int temp = n;
            product_digit = 1;
            while (temp > 0) {
                product_digit *= temp % 10;
                temp /= 10;
            }
            if(product_digit % t == 0) return n ;
            n++;
        }
        return n;
    }
};