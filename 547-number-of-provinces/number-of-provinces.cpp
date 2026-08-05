class Solution {
private:
    void dfs(int i, vector<int> adj[], vector<int>& visited) {
        visited[i] = 1; 
        for(auto it : adj[i]){
            if(visited[it] != 1 ){
                dfs(it , adj , visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                }
            }
        }
        int ans = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                ans++;
                dfs(i, adj, visited);
            }
        }
        return  ans ; 
    }
};