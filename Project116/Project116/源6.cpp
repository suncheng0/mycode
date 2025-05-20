////迪杰斯特拉算法只能用于路径都是正的情况
////如果出现负数，就要有bellman—ford算法
////bellman-ford算法如果有负权回路就会无限迭代
////bellmax-ford算法*不需要*排序
//#include<iostream>
//#include<vector>
//#include<algorithm> 
//#include<climits>
//#define MAXNUM 100000
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
//void bellman_ford(vector<int>& graph, vector<Edge>& bian, int src, int dst, int k);
//int main() {
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<int>graph(n, MAXNUM);//0号结点到该节点的最短距离
//
//    vector<Edge>bian;
//    while (m--) {
//        int x = 0, y = 0;
//        int weight;
//        cin >> x >> y >> weight;
//        Edge arc = { x - 1,y - 1,weight };
//        bian.push_back(arc);
//    }
//    int src, dst, k;
//    cin >> src >> dst >> k;
//    bellman_ford(graph, bian, src - 1, dst - 1, k);
//    return 0;
//}
//void bellman_ford(vector<int>& graph, vector<Edge>& bian, int src, int dst, int k) {
//    int arcnum = bian.size();
//    int vexnum = graph.size();
//    vector<int>pre_graph(vexnum, MAXNUM);
//    pre_graph[src] = 0;
//    graph[src] = 0;
//    for (int i = 0; i < k + 1; i++) {//遍历次数 
//        for (int j = 0; j < arcnum; j++) {
//            if (pre_graph[bian[j].beg] + bian[j].weight < graph[bian[j].end] && pre_graph[bian[j].beg] != MAXNUM) {
//                graph[bian[j].end] = pre_graph[bian[j].beg] + bian[j].weight;
//            }
//        }
//        for (int j = 0; j < vexnum; j++) {
//            pre_graph[j] = graph[j];
//        }
//    }
//    if (graph[dst] == MAXNUM) {
//        cout << "unreachable";
//    }
//    else {
//        cout << graph[dst];
//    }
//}