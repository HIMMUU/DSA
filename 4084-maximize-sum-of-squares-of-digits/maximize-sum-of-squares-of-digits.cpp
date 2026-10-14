// class Solution {
// public:
//     string maxSumOfSquares(int num, int sum) {
//         int start = pow(10, num - 1);
//         int end = start * 10;
//         int comp = 0;
//         int ans = -1;
//         for (int i = start; i < end; i++) {
//             int val = i;
//             int digitsum = 0;
//             int digi = 0;
//             while (val > 0) {
//                 digi = val % 10;
//                 val /= 10;
//                 digitsum += digi;
//             }
//             val = i;
//             int digisqaure = 0;

//             if (digitsum == sum) {
//                 while (val > 0) {
//                     int dig = val % 10;
//                     digisqaure += dig * dig;
//                     val /= 10;
//                 }
//                 if (comp < digisqaure) {
//                     comp = digisqaure;
//                     ans = i;
//                 }
//             }
//         }
//         string res;
//         while (ans > 0) {
//             int last = ans % 10;
//             res.push_back(last);
//             ans /= 10;
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans = "";

        while (num--) {
            int digit = min(9, sum);
            ans.push_back('0' + digit);
            sum -= digit;
        }

        if (sum > 0) return "";
        return ans;
    }
};