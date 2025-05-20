////迪杰斯特拉算法只能用于路径都是正的情况
////如果出现负数，就要有bellman—ford算法
////bellman-ford算法如果有负权回路就会无限迭代
////bellmax-ford算法*不需要*排序
////bellman-ford的队列优化
//#include<iostream>
//#include<vector>
//#include<algorithm> 
//#include<climits>
//#include<queue>
//#include<list>
//#define MAXNUM 10000
//using namespace std;
//typedef struct {
//    int beg;//起始结点
//    int end;//终止结点
//    int weight;//权重
//}Edge;
//class cmp {
//public:
//    bool operator()(Edge a, Edge b) {
//        if (a.beg == b.beg) {
//            return a.end < b.end;
//        }
//        return a.beg < b.beg;
//    }
//};
//void bellman_ford(vector<int>& graph, vector<list<Edge>>& bian);
//int main() {
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<int>graph(n, MAXNUM);//0号结点到该节点的最短距离
//    graph[0] = 0;
//    vector<list<Edge>>bian(n);//bian的下标时起始结点的下标 
//    while (m--) {
//        int x = 0, y = 0, weight;
//        cin >> x >> y >> weight;
//        Edge arc = { x - 1,y - 1,weight };
//        bian[x - 1].push_front(arc);
//    }
//    //for (auto k : bian) {
//    //    for (auto i : k) {
//    //        cout << i.beg << "->" << i.end << "权重" << i.weight << "  ";
//    //    }
//    //    cout << endl;
//    //}
//    bellman_ford(graph, bian);
//    return 0;
//}
//void bellman_ford(vector<int>& graph, vector<list<Edge>>& bian) {
//    queue<int>q;
//    vector<bool>visited(graph.size());
//    q.push(0);
//    visited[0] = 1;
//    while (!q.empty()) {
//        //从队列里取出一个顶点
//        //对以该点为起点的边进行松弛操作
//        //如果松弛操作后，顶点v的dis值发生了变化，则将v的邻接点加入队列
//        //如果队列里已经有v的该邻接点，则不再加入队列
//        //结束循环
//        int v = q.front();
//        q.pop();
//        visited[v] = 0;
//        for (Edge k : bian[v]) {//遍历以v为起点的边
//            if (graph[v] + k.weight < graph[k.end]) {
//                graph[k.end]=graph[v]+k.weight;//更新结点的距离值
//                if (!visited[k.end]) {
//                    q.push(k.end);
//                    visited[k.end] = 1;
//                }
//            }
//        }
//    }
//    if (graph.back() == MAXNUM) {
//        cout << "unconnected";
//    }
//    else {
//        cout << graph.back();
//    }
//}