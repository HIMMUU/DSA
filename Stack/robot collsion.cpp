#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int, int, char, int>> robot;
        vector<tuple<int, int, char, int>> survivor;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            robot.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(robot.begin(), robot.end());
        stack<tuple<int, int, char, int>> st;
        for (int i = 0; i < n; i++) {
            bool destroyed = false;
            while (!st.empty() && get<2>(robot[i]) == 'L' &&
                   get<2>(st.top()) == 'R') {
                if (get<1>(robot[i]) == get<1>(st.top())) {
                    destroyed = true;
                    st.pop();
                    break;
                } else if (get<1>(robot[i]) > get<1>(st.top())) {
                    get<1>(robot[i])--;
                    st.pop();
                } else {
                    get<1>(st.top())--;
                    destroyed = true;
                    break;
                }
            }

            if (destroyed == false) {
                st.push(robot[i]);
            }
            if (st.empty() && get<2>(robot[i]) == 'R') {
                st.push(robot[i]);
            }
        }

        while (!st.empty()) {
            survivor.push_back(st.top());
            st.pop();
        }

        sort(survivor.begin(), survivor.end(),
             [](auto& a, auto& b) { return get<3>(a) < get<3>(b); });

        for (int i = 0; i < survivor.size(); i++) {
            ans.push_back(get<1>(survivor[i]));
        }
        return ans;
    }
};