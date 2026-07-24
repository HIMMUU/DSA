class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char , int> mpp ; 
    
        for( char ch : s){
            mpp[ch]++ ; 

        }
        for( char ch : t){
            if(mpp[ch] > 0 )
            mpp[ch]-- ; 
            else return false ;
        }
        int ans = 0 ; 
        for( auto it : mpp){
            ans += it.second;
        }
       if (ans == 0 ) 
       return  true; 
       else return false ; 
    }
};