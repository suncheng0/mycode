////prim最小生成树
//#include<iostream>
//#include<vector>
//using namespace std;
//int findmin(vector<int>& d, vector<bool>& visited);
//void prim(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& d);
//int main() {
//    //建图
//    int v = 0, e = 0;
//    cin >> v >> e;
//    vector<vector<int>>graph(v, vector<int>(v, 0));
//    while (e--) {
//        int x = 0, y = 0, val = 0;
//        cin >> x >> y >> val;
//        graph[x - 1][y - 1] = graph[y - 1][x - 1] = val;
//    }
//    vector<bool>visited(v, false);
//    //
//     int m = 0;
//     for (auto k : graph) {
//        for (auto kk : k) {
//            cout << kk << " ";
//            if (kk > 0)m++;
//        } cout << endl;
//     }
//     cout << m << endl;
//    //prim
//    vector<int>d(graph.size());
//    prim(graph, visited, d);
//    int ans = 0;
//    for (int i = 0; i < d.size(); i++) {
//        ans += d[i];
//    }
//    cout << ans;
//    return 0;
//}
//void prim(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& d) {
//    //选一条最短的边，这边的终点要未访问
//    //将终点标记为访问
//    //根据该点更新所有的距离权重
//    //初始化
//    visited[0] = 1;
//    for (int i = 0; i < graph.size(); i++) {
//        if (visited[i] == 0) {
//            if (graph[0][i] > 0) {
//                d[i] = graph[0][i];
//            }
//        }
//    }
//    for (auto k : d)cout << k<<" "; cout << endl;
//     //遍历
//    for (int i = 0; i < graph.size() - 1; i++) {
//        //在d里找一条最短的边 这个边的终点要是未访问
//        int index = findmin(d, visited);
//        cout << index << " ";
//        visited[index] = 1;
//        //根据该点更新所有的距离权重
//        for (int j = 0; j < graph.size(); j++) {
//            if (visited[j] == 0 && graph[index][j]!=0&&(d[j] == 0 || d[j] > graph[index][j])) {
//                d[j] = graph[index][j];
//            }
//        }
//        cout << endl;
//        for (auto k : d)cout << k<<" "; cout << endl;
//    }
//    return;
//}
//int findmin(vector<int>& d, vector<bool>& visited) {
//    int min = 100001;
//    int index = 0;
//    for (int i = 0; i < d.size(); i++) {
//        if (visited[i] == 0 && d[i] != 0 && d[i] < min) {
//            min = d[i];
//            index = i;
//        }
//    }
//    return index;//返回的是最短边终点的下标
//}