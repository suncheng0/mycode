//// dijkstra算法
////最短路径问题
//#include <iostream>
//#include <vector>
//#include<climits>
//using namespace std;
//int getmin(vector<int>& d, vector<bool>& s);
//void dijkstra(vector<vector<int>>& graph);
//int main() {
//    //建图 有向图
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
//    while (m--) {
//        int x = 0, y = 0, val = 0;
//        cin >> x >> y >> val;
//        graph[x - 1][y - 1] = val;
//    }
//    for(int i=0;i<n;i++)graph[i][i] = 0;
//    //迪杰斯特拉
//    dijkstra(graph);
//    return 0;
//}
//void dijkstra(vector<vector<int>>& graph) {
//    // s数组 目标顶点到其他顶点的最短路径是否求得
//    // p数组 目标顶点到其他顶点的最短路径的前驱节点
//    // d数组 目标顶点到其他顶点的最短路径的长度
//    int n = graph.size();
//    vector<bool> s(n);
//    vector<int> p(n);
//    vector<int> d(n);
//    //初始化三个数组
//    s[0] = 1;
//    for (int i = 1; i < n; i++) {
//        if (graph[0][i] != 0) { //起点到i节点有边
//            d[i] = graph[0][i];
//        }
//        else{
//            d[i] =  INT_MAX; //起点到i结点没有边
//        }
//    }
//    d[0] = 0;
//    //cout << "p数组初始为" << endl;
//    //for (int i = 0; i < n; i++) {
//    //    cout << p[i] << " ";
//    //}cout << endl;
//    //遍历
//    for (int r = 0; r < n - 1; r++) {
//        //找一个没有访问过的，并且距离d最短的点
//        //把他改成已访问 并且根据他的graph来更新d数组
//        int index = getmin(d, s);
//        if (index == -1)
//            break; //所有结点已经访问过了，退出循环
//        s[index] = 1;
//        //cout<<"没有访问过的最短的结点是"<<index+1<<endl;
//        for (int i = 0; i < n; i++) {
//            if (s[i] == 0 &&graph[index][i]!=INT_MAX&& d[index] + graph[index][i] < d[i]) {
//                d[i] = d[index] + graph[index][i];
//                p[i] = index; //更新前驱节点  p里存放的是结点编号 从1开始
//            }
//        }
//        //cout<<"p数组更新后为"<<endl;
//        //for (int i = 0; i < n; i++) {
//        //    cout<<p[i]<<" ";
//        //}cout<<endl;
//    }
//}
//int getmin(vector<int>& d, vector<bool>& s) {
//    int min = INT_MAX;
//    int index = 0;
//    int have_novisited = false;
//    for (int i = 0; i < d.size(); i++) {
//        if (s[i] == 0) {
//            have_novisited = true;
//            if (d[i] < min) {
//                min = d[i];
//                index = i;
//            }
//        }
//    }
//    if (have_novisited == false)
//        return -1;
//    else
//        return index;
//}