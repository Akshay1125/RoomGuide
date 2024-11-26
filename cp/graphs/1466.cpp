class Solution {
public:
    int ans=0;
    int dfs(int node, vector<vector<pair<int, bool>>> &adj, vector<int> &vis) {
        
        vis[node]=1;
        

        for(auto it : adj[node]) {

            if(!vis[it.first]) {
                if(it.second) ans++;
                dfs(it.first,adj,vis);
            }
        }

        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int, bool>>> adj(n);

        for(int i = 0; i < connections.size(); i++) {

            adj[connections[i][0]].push_back({connections[i][1], true});
            adj[connections[i][1]].push_back({connections[i][0], false});
        }
        
        vector<int> vis(n,0);

        return dfs(0,adj,vis);
        
    }
};