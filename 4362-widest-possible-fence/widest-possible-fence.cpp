// class Solution {
// public:
//     int maximumWidth(vector<int>& planks) {
//         if (planks.size() == 1)
//             return 1;
//         unordered_set<long long> st;
//         for (int x : planks) {
//             st.insert(x);
//         }
//         int n = planks.size();
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 st.insert(planks[i] + planks[j]);
//             }
//         }
//         sort(planks.begin(), planks.end());
//         int ans = 0;
//         for (auto& T : st) {
//             int curr = 0;
//             int l = 0;
//             int r = n - 1;
//             while (l <= r && planks[l] == T) {
//                 curr++;
//                 l++;
//             }

//             while (l <= r && planks[r] == T) {
//                 curr++;
//                 r--;
//             }

//             while (l < r) {
                
//                  if (planks[l] + planks[r] < T)
//                     l++;
//                 else if (planks[l] + planks[r] > T)
//                     r--;
//                 else {
//                     curr++;
//                     l++;
//                     r--;
//                 }
//             }
//             ans = max(curr, ans);
//         }
//         return ans;
//     }
// };
 class Solution {
 public:
     int maximumWidth(vector<int>& planks) {
    unordered_map<int, int> cnt;
        for (int p : planks) cnt[p]++;
        
        vector<int> vals;
        for (auto& [v, c] : cnt) vals.push_back(v);
        sort(vals.begin(), vals.end());
        
        int k = vals.size();
        unordered_map<long long, int> width;
        
        // Singles and self-pairs (v + v = 2v)
        for (int v : vals) {
            int c = cnt[v];
            width[v] += c;
            width[2LL * v] += c / 2;
        }
        
        // Pairs of distinct values
        for (int i = 0; i < k; i++) {
            int vi = vals[i], ci = cnt[vi];
            for (int j = i + 1; j < k; j++) {
                int vj = vals[j], cj = cnt[vj];
                width[(long long)vi + vj] += min(ci, cj);
            }
        }
        
        int ans = 0;
        for (auto& [h, w] : width) ans = max(ans, w);
        return ans;}};