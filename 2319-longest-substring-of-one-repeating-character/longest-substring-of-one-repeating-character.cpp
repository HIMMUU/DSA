//Brute Force
//  class Solution {
//     private: 
//         int longsubstring(string  s ) {
//             int n = s.length();
//             int l = 0 , r  = 0 ; 
//             int ans = 0 ;
//             while( r < n){
//                 if( s[l] == s[r]){
//                     ans = max( ans , r-l+1 );

//                 }else{
//                     while(s[l] != s[r]){
//                         l++;
//                     }
//                 }
//                 r++;
//             }
//             return ans ; 


//         }
// public:
//     vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
//         vector<int> ans  ; 
//         for( int i = 0 ; i < queryIndices.size() ; i++ ){
//            s[queryIndices[i]] =  queryCharacters[i]  ;
//             ans.push_back(longsubstring(s));
//         }
//         return ans ; 
//     }
// };

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size();
        vector<int> pre(4 * n), suf(4 * n), maxLen(4 * n);
        vector<char> leftChar(4 * n), rightChar(4 * n);

        auto pushUp = [&](int u, int l, int r) {
            int mid = (l + r) >> 1;
            int leftLen = mid - l + 1, rightLen = r - mid;
            int left = u << 1, right = u << 1 | 1;
            leftChar[u] = leftChar[left];
            rightChar[u] = rightChar[right];
            pre[u] = pre[left];
            if (pre[left] == leftLen && rightChar[left] == leftChar[right]) {
                pre[u] = pre[left] + pre[right];
            }
            suf[u] = suf[right];
            if (suf[right] == rightLen && rightChar[left] == leftChar[right]) {
                suf[u] = suf[right] + suf[left];
            }
            maxLen[u] = max(maxLen[left], maxLen[right]);
            if (rightChar[left] == leftChar[right]) {
                maxLen[u] = max(maxLen[u], suf[left] + pre[right]);
            }
        };

        function<void(int, int, int)> build = [&](int u, int l, int r) {
            if (l == r) {
                pre[u] = 1;
                suf[u] = 1;
                maxLen[u] = 1;
                leftChar[u] = s[l];
                rightChar[u] = s[l];
                return;
            }
            int mid = (l + r) >> 1;
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
            pushUp(u, l, r);
        };

        function<void(int, int, int, int, char)> update =
            [&](int u, int l, int r, int pos, char ch) {
                if (l == r) {
                    leftChar[u] = ch;
                    rightChar[u] = ch;
                    return;
                }
                int mid = (l + r) >> 1;
                if (pos <= mid) {
                    update(u << 1, l, mid, pos, ch);
                } else {
                    update(u << 1 | 1, mid + 1, r, pos, ch);
                }
                pushUp(u, l, r);
            };

        build(1, 0, n - 1);
        int k = queryIndices.size();
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = maxLen[1];
        }
        return ans;
    }
};