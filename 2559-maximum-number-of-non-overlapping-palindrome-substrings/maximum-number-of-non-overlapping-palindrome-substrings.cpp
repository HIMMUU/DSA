class Solution {
private:
    bool palindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int ans = 0;
        int start = 0;

        for (int end = k - 1; end < n; end++) {

            for (int i = start; i <= end - k + 1; i++) {

                if (palindrome(s, i, end)) {
                    ans++;
                    start = end + 1;
                    break;
                }
            }
        }

        return ans;
    }
};