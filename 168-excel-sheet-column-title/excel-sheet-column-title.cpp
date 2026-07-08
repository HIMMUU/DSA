class Solution {
public:
    string convertToTitle(int CN) {
        string ans ;

        while( CN ){
            CN--;
            ans += char( CN%26 + 'A');
            CN = CN/26;

        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};