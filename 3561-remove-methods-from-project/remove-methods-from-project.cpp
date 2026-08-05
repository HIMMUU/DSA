class Solution {
    private:
    void  dfs( int node , vector<vector<int>> &adj,vector<int> &vis ,  vector<int> & comp ){
        vis[node] = 1 ; 
        comp.push_back(node);
        for( int nei : adj[node]){
            if(vis[nei] == 0 ){
                dfs(nei ,adj, vis ,comp );
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& inv) {
     vector<vector<int>> adj(n);
vector<vector<int>> unadj(n);
        for( int i = 0 ; i < inv.size() ; i++){
            adj[inv[i][0]].push_back(inv[i][1]);
            unadj[inv[i][0]].push_back(inv[i][1]);
            unadj[inv[i][1]].push_back(inv[i][0]);
        }
        

        vector<vector<int>> component ; 
        vector<int> vis( n , 0 );
        for( int i = 0 ; i < n ; i++ ){
            if(vis[i] == 0 ){
                vector<int> comp ; 
                dfs( i , unadj , vis , comp);
                component.push_back(comp);
            }
        }

        vector<int> visit(n,0) ;
        vector<int> tempcomp;
        
        dfs( k , adj , visit , tempcomp );
        unordered_map<int,int> mpp ;
        for( int k : tempcomp){
            mpp[k]++;
        }
        
      vector< int> ans ;
        for(int i = 0 ; i<component.size() ; i++){
            bool lena = true;
            for( int j =0 ; j <component[i].size() ; j++){
                if(component[i][j] == k){
                    if( component[i].size() == tempcomp.size()){
                        lena = false;
                        break;
                    }
                }
            }
            for( int  j = 0 ; j < component[i].size() && lena == true  ; j++){
                    ans.push_back(component[i][j]);
            }
        }
        return ans;

        
    }
};