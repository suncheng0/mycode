////�Ͻ�˹�����㷨ֻ������·�������������
////������ָ�������Ҫ��bellman��ford�㷨
////bellman-ford�㷨����и�Ȩ��·�ͻ����޵���
////bellmax-ford�㷨*����Ҫ*����
////bellman-ford�Ķ����Ż�
//#include<iostream>
//#include<vector>
//#include<algorithm> 
//#include<climits>
//#include<queue>
//#include<list>
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
//void bellman_ford(vector<int>& graph, vector<list<Edge>>& bian);
//int main() {
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<int>graph(n, MAXNUM);//0�Ž�㵽�ýڵ����̾���
//    graph[0] = 0;
//    vector<list<Edge>>bian(n);//bian���±�ʱ��ʼ�����±� 
//    while (m--) {
//        int x = 0, y = 0, weight;
//        cin >> x >> y >> weight;
//        Edge arc = { x - 1,y - 1,weight };
//        bian[x - 1].push_front(arc);
//    }
//    //for (auto k : bian) {
//    //    for (auto i : k) {
//    //        cout << i.beg << "->" << i.end << "Ȩ��" << i.weight << "  ";
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
//        //�Ӷ�����ȡ��һ������
//        //���Ըõ�Ϊ���ı߽����ɳڲ���
//        //����ɳڲ����󣬶���v��disֵ�����˱仯����v���ڽӵ�������
//        //����������Ѿ���v�ĸ��ڽӵ㣬���ټ������
//        //����ѭ��
//        int v = q.front();
//        q.pop();
//        visited[v] = 0;
//        for (Edge k : bian[v]) {//������vΪ���ı�
//            if (graph[v] + k.weight < graph[k.end]) {
//                graph[k.end]=graph[v]+k.weight;//���½��ľ���ֵ
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