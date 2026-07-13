class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        for (int i = 1; i < 9; i++) {
            q.push(i);
        }
   

        while (!q.empty()) {
           int  num = q.front();
            q.pop();

            if (num >= low && num <= high) {
                ans.push_back(num);
            }
            int lg = num %10 ; 
            if (lg < 9) {
                num = (num * 10) + (lg+ 1);
                q.push(num);
            }
        }
        return ans;
    }
};