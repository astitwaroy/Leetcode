class Solution {
public:
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int &nodes, int &degreesum){
    vis[node] = 1;
    nodes++;
    degreesum += adj[node].size();
    for(int it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, nodes, degreesum);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                int nodes = 0;
                int degreesum = 0;
                dfs(i, adj, vis, nodes, degreesum);
                int edgecount = degreesum / 2;
                if(edgecount == nodes * (nodes - 1) / 2) ans++;
            }
        }
        return ans;
    }
};