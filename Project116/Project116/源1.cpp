////dijkstra堆优化版
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<climits>
//#include<list>
//using namespace std;
//class Edge {
//public:
//    int to;
//    int weight;
//    Edge(int x, int y) :to(x), weight(y) {}
//};
//void dijkstra(vector<list<Edge>>& graph, vector<bool>& visited);
////struct cmp {
////    bool operator()(pair<int, int>a, pair<int, int>b) {
////        return a.second > b.second;
////    }
////};
//auto  cmp = [&](pair<int, int>&a, pair<int, int>&b) {
//    return a.second > b.second;
//};
//int main() {
//    //建图(邻接表)
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<list<Edge>>graph(n);//建立邻接表
//    while (m--) {
//        int beg, end, wei;
//        cin >> beg >> end >> wei;
//        Edge edge(end - 1, wei);
//        graph[beg - 1].push_front(edge);
//    }
//    vector<bool>visited(n);
//    //迪杰斯特拉
//    dijkstra(graph,visited);
//    return 0;
//}
//
////迪杰斯特拉
//void dijkstra(vector<list<Edge>>& graph,vector<bool>&visited) {
//    //从未访问的结点里找一个最近的
//    //把该节点设置成已访问
//    //根据该结点来更细权重
//    int n = graph.size();
//    vector<int>jiedian(n,100000 );
//    //pair表示<结点编号，到该节点的最短路程>
//    priority_queue < pair<int, int>, vector<pair<int, int>>, decltype(cmp)> dui(cmp);//根据权重来对未访问的结点进行排序
//        dui.push(pair<int, int>(0, 0));
//        while (!dui.empty()) {
//            //取一个结点 把它设置成已经访问 更新
//            pair<int, int>cur = dui.top();dui.pop();
//            if (visited[cur.first] == 1) {
//                continue;
//            }
//            visited[cur.first] = 1;
//            jiedian[cur.first] = cur.second;//起点到cur.first号结点的最短距离是cur.second
//            for (Edge edge : graph[cur.first]) {
//                pair<int, int>newp = { edge.to,cur.second + edge.weight };
//                dui.push(newp);
//            }//把新的距离对丢到堆里
//        }
//        if (jiedian.back() != 100000)cout << jiedian.back();
//        else cout << -1;
//}