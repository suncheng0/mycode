//#include<iostream>
//#include<vector>
//#define MAXNUM 100000
//using namespace std;
//void floyd(vector<vector<int>>& graph, vector<vector<int>>& d);
//int main() {
//    //½¨Í¼
//    int vexnum = 0, arcnum = 0;
//    cin >> vexnum >> arcnum;
//    vector<vector<int>>graph(vexnum, vector<int>(vexnum, MAXNUM));
//    for (int i = 0; i < vexnum; i++) {
//        graph[i][i] = 0;
//    }
//    while (arcnum--) {
//        int beg = 0, end = 0, wei = 0;
//        cin >> beg >> end >> wei;
//        graph[beg - 1][end - 1] = wei;
//        graph[end - 1][beg - 1] = wei;
//    }
//    cout<<"ÊäÈëQ"<<endl;
//    int Q = 0;
//    cin >> Q;
//    vector<vector<int>>d(vexnum, vector<int>(vexnum, MAXNUM));
//    floyd(graph, d);
//    while (Q--) {
//        int start = 0, end = 0;
//        cin >> start >> end;
//        if (d[start - 1][end - 1] != MAXNUM)cout << d[start - 1][end - 1];
//        else cout << -1;
//    }
//    return 0;
//}
//void floyd(vector<vector<int>>& graph, vector<vector<int>>& d) {
//    int vexnum = graph.size();
//    d=graph;
//    for (int i = 0; i < vexnum; i++) {
//        for (int j = 0; j < vexnum; j++) {
//            for (int k = 0; k < vexnum; k++) {
//                if (d[j][i] + d[i][k] < d[j][k]) {
//                    d[j][k] = d[j][i] + d[i][k];
//                }
//            }
//        }
//    }
//}