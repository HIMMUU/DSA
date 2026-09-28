class Solution {
public:
    int maxDepth(string s) {
        int ans = 0 ; 
        int st = 0;
        for(auto ch : s){
            if(ch == '(')
             st++;
            ans = max(ans,st );
             if(ch == ')')
             st--;

        }
        return ans;
    }
};