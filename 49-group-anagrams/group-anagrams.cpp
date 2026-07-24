class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res; 
     unordered_map<string , vector<int> > mpp ; 
     vector<string> st = strs;
     for( int i = 0 ;i < st.size() ; i++){
        
        sort(st[i].begin() , st[i].end());
        mpp[st[i]].push_back(i);
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