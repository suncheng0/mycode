////�Ͻ�˹�����㷨ֻ������·�������������
////������ָ�������Ҫ��bellman��ford�㷨
////bellman-ford�㷨����и�Ȩ��·�ͻ����޵���
////bellmax-ford�㷨*����Ҫ*����
////�����б߽����ɳ�n-1�β�����nΪ�ڵ�������
//#include<iostream>
//#include<vector>
//#include<algorithm> 
//#include<climits>
//#define MAXNUM 10000
//using namespace std;
//typedef struct {
//    int beg;//��ʼ���
//    int end;//��ֹ���
//    int weight;//Ȩ��
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
//    vector<int>graph(n, MAXNUM);//0�Ž�㵽�ýڵ����̾���
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
//    for (int i = 0; i < vexnum; i++) {//��������==����ĸ���
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