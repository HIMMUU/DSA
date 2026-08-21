class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair <int , int>> num(26 ) ;
        for( int i = 0 ; i < num.size() ; i++){
            num[i].first = 0 ; 
            num[i].second = 0 ; 
         } 
        for( int i = 0 ; i < s.length() ; i++  ){
            
            num[s[i] - 97].first += 1 ; 
         if(num[s[i] - 97].second == 0 )
            num[s[i] - 97].second  = i ; 
        }
        int ans = INT_MAX ; 
        for( int i  = 0 ; i < s.length() ; i++){
            if( num[s[i] - 97].first == 1) if(   num[s[i] - 97].second < ans  ){
                ans = num[s[i] - 97].second;
            } 
        }
        return ans == INT_MAX  ? -1 : ans ; 
    }
};

