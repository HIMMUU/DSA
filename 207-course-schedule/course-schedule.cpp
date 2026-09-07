class Solution {
private:

    bool dfs(int node,
             vector<bool>& vis,
             vector<bool>& path,
             vector<vector<int>>& adj) {

        vis[node] = true;
        path[node] = true;

        for (auto adjn : adj[node]) {

            // Node is not visited
            if (!vis[adjn]) {

                if (dfs(adjn, vis, path, adj))
                    return true;
            }

            // Node is already in current DFS path
            else if (path[adjn]) {
                return true;
            }
        }

        // Backtracking
        path[node] = false;

        return false;
    }

public:

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto& prerequisite : prerequisites) {

            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];

            adj[prerequisiteCourse].push_back(course);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> path(numCourses, false);

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {

                if (dfs(i, vis, path, adj))
                    return false;
            }
        }

        return true;
    }
};