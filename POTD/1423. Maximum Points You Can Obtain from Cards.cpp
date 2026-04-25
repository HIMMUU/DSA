#include <iostream>
using namespace std;

int main() {
	// your code goes here  int res1 = false ;
vector<int> arr =	{1,1000,1};
int k = 1;
	  int n = arr.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int res =0;
        int count = 0;
        int Tsum = 0;
        for (int  i = 0 ; i< n ; i++ ) {
            Tsum += arr[i];
        }
         if (k == n) {
                return Tsum;
            }
       while (r < n) {
            
            sum += arr[r];

            while (count > n - k) {
                sum -= arr[l];
                l++;
                count --;
            }
            if (n - count ==  k) {

                res = max(res, Tsum - sum);
            }
          
            r++;  count = r - l + 1;
        }
            cout << res;
        

}
