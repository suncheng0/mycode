#include <iostream>
#include <vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
void dfs(int, int, vector<vector<int>>&, vector<vector<bool>>&, int&, int);
int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
int max_squre = 0;
int main() {
    //建图
    unordered_map<int, int>hash;//编号，面积
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m, 0));
    vector<vector<bool>> used(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    //
    int id = 1;//第一个岛屿是1号岛屿
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (used[i][j] == 0 && graph[i][j] == 1) {
                //深度优先搜索
                int dfs_squre = 0;
                dfs(i, j, graph, used, dfs_squre, id);
                hash[id] = dfs_squre;
                id++;
                if (max_squre < dfs_squre)max_squre = dfs_squre;
            }
        }
    }
    for (auto k : hash)cout << k.first << " " << k.second << endl;
    //
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (graph[x][y] == 0) {
                int squre = 1;
                unordered_set<int>set;
                for (int i = 0; i < 4; i++) {
                    int nextx = x + dir[i][0];
                    int nexty = y + dir[i][1];
                    if (nextx < 0 || nextx == graph.size() || nexty < 0 ||
                        nexty == graph[0].size()) {
                        continue;
                    }
                    if (graph[nextx][nexty] != 0 && set.find(graph[nextx][nexty]) == set.end()) {
                        squre += hash[graph[nextx][nexty]];
                        set.insert(graph[nextx][nexty]);
                    }
                }
                if (squre > max_squre)max_squre = squre;
            }
        }
    }
    cout << max_squre;
    return 0;
}

void dfs(int x, int y, vector<vector<int>>& graph,
    vector<vector<bool>>& visited, int& dfs_squre, int id) {
    if (visited[x][y] == 1) {
        return;
    }
    visited[x][y] = 1;
    graph[x][y] = id;
    dfs_squre++;
    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx == graph.size() || nexty < 0 ||
            nexty == graph[0].size()) {
            continue;
        }
        if (visited[nextx][nexty] == 1) {
            continue;
        }
        if (graph[nextx][nexty] == 1) {
            dfs(nextx, nexty, graph, visited, dfs_squre, id);
        }
    }
}