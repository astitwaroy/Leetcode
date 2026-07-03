class Solution {
public:
bool possible(int mid,
    vector<vector<pair<int,int>>>& adj,vector<int>& topo,vector<bool>& online,long long k,int n)
    {
        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[0] = 0;
        for(int u : topo)
        {
            if(dist[u] == INF)
                continue;
            // Intermediate nodes must be online
            if(u != 0 && u != n - 1 && !online[u])
                continue;
                 for(auto [v, cost] : adj[u])
            {
                // Edge must satisfy minimum edge cost
                if(cost < mid)
                    continue;

                // Intermediate destination node must be online
                if(v != n - 1 && !online[v])
                    continue;

                if(dist[u] + cost < dist[v])
                {
                    dist[v] = dist[u] + cost;
                }
            }
        }
        return dist[n - 1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n);
        int high = 0;
        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            adj[u].push_back({v, cost});
            indegree[v]++;

            high = max(high, cost);
        }
        // Topological Sort
        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for(auto [v, cost] : adj[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        int low = 0;
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(possible(mid, adj, topo, online, k, n))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};