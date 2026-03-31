#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {

            if (arr[i] > 0) {
                st.push(arr[i]);
            } else {
                bool destroyed = false;

                while (!st.empty() && st.top() > 0 && arr[i] < 0) {

                    if (st.top() < -arr[i]) {
                        st.pop();
                    } else if (st.top() == -arr[i]) {
                        st.pop();
                        destroyed = true;
                        break;
                    } else {
                        destroyed = true;
                        break;
                    }
                }

                if (!destroyed && (st.empty() || st.top() < 0)) {
                    st.push(arr[i]);
                }
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};