////dijkstra���Ż���
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
//    //��ͼ(�ڽӱ�)
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<list<Edge>>graph(n);//�����ڽӱ�
//    while (m--) {
//        int beg, end, wei;
//        cin >> beg >> end >> wei;
//        Edge edge(end - 1, wei);
//        graph[beg - 1].push_front(edge);
//    }
//    vector<bool>visited(n);
//    //�Ͻ�˹����
//    dijkstra(graph,visited);
//    return 0;
//}
//
////�Ͻ�˹����
//void dijkstra(vector<list<Edge>>& graph,vector<bool>&visited) {
//    //��δ���ʵĽ������һ�������
//    //�Ѹýڵ����ó��ѷ���
//    //���ݸý������ϸȨ��
//    int n = graph.size();
//    vector<int>jiedian(n,100000 );
//    //pair��ʾ<����ţ����ýڵ�����·��>
//    priority_queue < pair<int, int>, vector<pair<int, int>>, decltype(cmp)> dui(cmp);//����Ȩ������δ���ʵĽ���������
//        dui.push(pair<int, int>(0, 0));
//        while (!dui.empty()) {
//            //ȡһ����� �������ó��Ѿ����� ����
//            pair<int, int>cur = dui.top();dui.pop();
//            if (visited[cur.first] == 1) {
//                continue;
//            }
//            visited[cur.first] = 1;
//            jiedian[cur.first] = cur.second;//��㵽cur.first�Ž�����̾�����cur.second
//            for (Edge edge : graph[cur.first]) {
//                pair<int, int>newp = { edge.to,cur.second + edge.weight };
//                dui.push(newp);
//            }//���µľ���Զ�������
//        }
//        if (jiedian.back() != 100000)cout << jiedian.back();
//        else cout << -1;
//}