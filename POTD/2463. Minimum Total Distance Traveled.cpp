
#include <iostream>
using namespace std;
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // expand factories
        vector<int> fac;
        for (auto &f : factory) {
            int pos = f[0], cap = f[1];
            while (cap--) fac.push_back(pos);
        }

        int n = robot.size();
        int m = fac.size();

        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 1e15));

        // base case
        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // skip
                dp[i][j] = dp[i][j-1];

                // take
                dp[i][j] = min(dp[i][j],
                    dp[i-1][j-1] + abs(robot[i-1] - fac[j-1]));
            }
        }

        return dp[n][m];
    }
};

// my code withoout dp
// class Solution {
// public:
//     int CheckDist(int rbtidx, vector<int>& robot,
//                   vector<vector<int>>& factory) {
//         int minDist = INT_MAX;
//         pair<int, long long> ans;
//         for (int i = 0; i < factory.size(); i++) {
//             if (factory[i][1] > 0) {
//                 int dist =
//                     max(rbtidx, factory[i][0]) - min(rbtidx, factory[i][0]);
//                 if (minDist > dist) {
//                     ans.first = i;
//                     minDist = dist;
//                     ans.second = dist;
//                 }
//             }
//         }
//         factory[ans.first][1]--;
//         return ans.second;
//     }

//     long long minimumTotalDistance(vector<int>& robot,
//                                    vector<vector<int>>& factory) {
//         long long res = 0;

//         for (int i = 0; i < robot.size(); i++) {
//             long long curr = CheckDist(robot[i], robot,
//                                      factory));
//                                      res += curr
//         }
//         return res;
//     }
};