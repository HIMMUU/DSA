class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; 
     unordered_map<string , vector<int> > mpp ; 
     
     for( int i = 0 ;i < strs.size() ; i++){
        string key = strs[i];
        sort(key.begin() , key.end());
        mpp[key].push_back(i);
        
     }
     for( auto it : mpp){
        vector<int> temp = it.second ; 
        vector<string> tempo ; 
        for(int i = 0 ; i< temp.size() ; i++){
            tempo.push_back(strs[temp[i]]);
        }
        res.push_back(tempo);

     }
     return res; 
    }
};