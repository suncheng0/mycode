//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//void dfs(int, int, vector<vector<int>>&, vector<vector<bool>>&, int&);
//void bfs(int, int, vector<vector<int>>&, vector<vector<bool>>&, int&);
//int max_squre = 0;
//int main() {
//    //建图
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>>graph(n, vector<int>(m, 0));
//    vector<vector<bool>>used(n, vector<bool>(m, false));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cin >> graph[i][j];
//        }
//    }
//    //统计岛屿的个数
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (used[i][j] == 0 && graph[i][j] == 1) {
//                //深度优先搜索
//                int dfs_squre = 0;
//                dfs(i, j, graph, used, dfs_squre);
//                if (dfs_squre > max_squre)max_squre = dfs_squre;
//                //广度优先搜索
//                //int bfs_squre = 0;
//                // bfs(i, j, graph, used,bfs_squre);
//                // if (bfs_squre > max_squre)max_squre = bfs_squre;
//            }
//        }
//    }
//    cout << max_squre;
//    return 0;
//}
//void dfs(int i, int j, vector<vector<int>>& graph, vector<vector<bool>>& used, int& dfs_squre) {
//    used[i][j] = 1;
//    dfs_squre++;
//    //无路可走了，返回
//    //上
//    if (i != 0 && graph[i - 1][j] == 1 && used[i - 1][j] == 0) {
//        dfs(i - 1, j, graph, used, dfs_squre);
//    }
//    //下
//    if (i != graph.size() - 1 && graph[i + 1][j] == 1 && used[i + 1][j] == 0) {
//        dfs(i + 1, j, graph, used, dfs_squre);
//    }
//    //左
//    if (j != 0 && graph[i][j - 1] == 1 && used[i][j - 1] == 0) {
//        dfs(i, j - 1, graph, used, dfs_squre);
//    }
//    //右
//    if (j != graph[0].size() - 1 && graph[i][j + 1] == 1 && used[i][j + 1] == 0) {
//        dfs(i, j + 1, graph, used, dfs_squre);
//    }
//}
//void bfs(int i, int j, vector<vector<int>>& graph, vector<vector<bool>>& used, int& bfs_squre) {
//    queue<pair<int, int>>q;
//    q.push(pair<int, int>(i, j));
//    used[i][j] = 1;
//    while (!q.empty()) {
//        int x = q.front().first;
//        int y = q.front().second;
//        q.pop();
//        bfs_squre++;
//        if (x != 0 && graph[x - 1][y] == 1 && used[x - 1][y] == 0) {
//            q.push(pair<int, int>(x - 1, y));//上
//            used[x - 1][y] = 1;
//        }
//        if (x != graph.size() - 1 && graph[x + 1][y] == 1 && used[x + 1][y] == 0) {
//            q.push(pair<int, int>(x + 1, y));//下
//            used[x + 1][y] = 1;
//        }
//
//        if (y != 0 && graph[x][y - 1] == 1 && used[x][y - 1] == 0) {
//            q.push(pair<int, int>(x, y - 1));//左
//            used[x][y - 1] = 1;
//        }
//        if (y != graph[0].size() - 1 && graph[x][y + 1] == 1 && used[x][y + 1] == 0) {
//            q.push(pair<int, int>(x, y + 1));//右
//            used[x][y + 1] = 1;
//        }
//    }
//}