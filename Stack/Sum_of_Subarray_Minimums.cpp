# include<iostream>
using namespace std;
class Solution {
public:
    long long MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, 0);
        vector<int> psee(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            psee[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        long long total = 0;
        for (int i = 0; i < n; i++) {
            int right = nse[i] - i;
            int left = i - psee[i];
            total = (total + (right * left % MOD) * arr[i] % MOD) % MOD;
        }
        return total;
    }
};