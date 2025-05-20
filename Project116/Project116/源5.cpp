////迪杰斯特拉算法只能用于路径都是正的情况
////如果出现负数，就要有bellman—ford算法
////bellman-ford算法如果有负权回路就会无限迭代
////bellmax-ford算法*不需要*排序
////对所有边进行松弛n-1次操作（n为节点数量）
//#include<iostream>
//#include<vector>
//#include<algorithm> 
//#include<climits>
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
//void bellman_ford(vector<int>& graph, vector<Edge>& bian);
//int main() {
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<int>graph(n, MAXNUM);//0号结点到该节点的最短距离
//    graph[0] = 0;
//    vector<Edge>bian;
//    while (m--) {
//        int x = 0, y = 0, weight;
//        cin >> x >> y >> weight;
//        Edge arc = { x - 1,y - 1,weight };
//        bian.push_back(arc);
//    }
//    sort(bian.begin(), bian.end(), cmp());
//    bellman_ford(graph, bian);
//
//    return 0;
//}
//void bellman_ford(vector<int>& graph, vector<Edge>& bian) {
//    int arcnum = bian.size();
//    int vexnum = graph.size();
//    bool haveFuhuan = false;
//    for (int i = 0; i < vexnum; i++) {//遍历次数==顶点的个数
//        for (int j = 0; j < arcnum; j++) {
//            if (graph[bian[j].beg] + bian[j].weight < graph[bian[j].end] && graph[bian[j].beg] != MAXNUM) {
//                if (i == vexnum - 1) {
//                    haveFuhuan == 1;
//                }
//                graph[bian[j].end] = graph[bian[j].beg] + bian[j].weight;
//            }
//        }
//        for (auto k : graph) {
//            cout << k << " ";
//        }cout << endl;
//    }
//    if (haveFuhuan == 1) {
//        cout << "circle";
//    }
//    else if (graph.back() == MAXNUM) {
//        cout << "unconnected";
//    }
//    else {
//        cout << graph.back();
//    }
//}