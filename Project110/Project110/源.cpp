#include<iostream>
#include<vector>
using namespace std;
void dfs(int , int , vector<vector<int>>& , vector<vector<bool>>& );
int ans = 0;
int main() {
    //建图
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>>graph(n, vector<int>(m, 0));
    vector<vector<bool>>used(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    //统计岛屿的个数
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (used[i][j] == 0 && graph[i][j] == 1) {
                dfs(i, j, graph, used);
                ans++;
                cout<<endl;
            }
        }
    }
    cout<<ans;
    return 0;
}
void dfs(int i, int j, vector<vector<int>>& graph, vector<vector<bool>>& used) {
    used[i][j] = 1;
    //无路可走了，返回
    //上
    if (i != 0 && graph[i - 1][j] == 1 && used[i - 1][j] == 0) {
        dfs(i - 1, j, graph, used);
    }
    //下
    if (i != graph.size() - 1 && graph[i + 1][j] == 1 && used[i + 1][j] == 0) {
        dfs(i + 1, j, graph, used);
    }
    //左
    if (j != 0 && graph[i][j - 1] == 1 && used[i][j - 1] == 0) {
        dfs(i, j - 1, graph, used);
    }
    //右
    if (j != graph[0].size()-1 && graph[i][j + 1] == 1 && used[i][j + 1] == 0) {
        dfs(i, j + 1, graph, used);
    }
}