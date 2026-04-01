#include<iostream>
using namespace std;
class Solution {
public:
    string removeKdigits(string arr, int k) {
        int n = arr.length();
        stack<char> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && k != 0 && arr[i] < st.top()) {
                st.pop();
                k--;
            }

            if (st.empty() && arr[i] == '0')
                continue;

            st.push(arr[i]);
        }

        while (k != 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res.empty() ? "0" : res;
    }
};