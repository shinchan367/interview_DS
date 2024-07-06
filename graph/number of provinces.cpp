#include <vector>
using namespace std;

class Solution {
    // Helper function to perform DFS on the graph
    void dfs(int node, vector<int> adjl[], vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adjl[node]) {
            if (!vis[it]) {
                dfs(it, adjl, vis);
            }
        }
    }
    
public:
    // Main function to find the number of provinces
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjl[n];
        
        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n, 0);
        int cnt = 0;
        
        // Count the number of connected components (provinces)
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adjl, vis);
            }
        }
        
        return cnt;
    }
};
//************************************************************************************************************
//bfs
class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visit) {
        queue<int> q;
        q.push(node);
        visit[node] = true;

        while (!q.empty()) {
            node = q.front();
            q.pop();

            for (int i = 0; i < isConnected.size(); i++) {
                if (isConnected[node][i] && !visit[i]) {
                    q.push(i);
                    visit[i] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int numberOfComponents = 0;
        vector<bool> visit(n);

        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                numberOfComponents++;
                bfs(i, isConnected, visit);
            }
        }

        return numberOfComponents;
    }
};
