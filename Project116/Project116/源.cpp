//// dijkstra�㷨
////���·������
//#include <iostream>
//#include <vector>
//#include<climits>
//using namespace std;
//int getmin(vector<int>& d, vector<bool>& s);
//void dijkstra(vector<vector<int>>& graph);
//int main() {
//    //��ͼ ����ͼ
//    int n = 0, m = 0;
//    cin >> n >> m;
//    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
//    while (m--) {
//        int x = 0, y = 0, val = 0;
//        cin >> x >> y >> val;
//        graph[x - 1][y - 1] = val;
//    }
//    for(int i=0;i<n;i++)graph[i][i] = 0;
//    //�Ͻ�˹����
//    dijkstra(graph);
//    return 0;
//}
//void dijkstra(vector<vector<int>>& graph) {
//    // s���� Ŀ�궥�㵽������������·���Ƿ����
//    // p���� Ŀ�궥�㵽������������·����ǰ���ڵ�
//    // d���� Ŀ�궥�㵽������������·���ĳ���
//    int n = graph.size();
//    vector<bool> s(n);
//    vector<int> p(n);
//    vector<int> d(n);
//    //��ʼ����������
//    s[0] = 1;
//    for (int i = 1; i < n; i++) {
//        if (graph[0][i] != 0) { //��㵽i�ڵ��б�
//            d[i] = graph[0][i];
//        }
//        else{
//            d[i] =  INT_MAX; //��㵽i���û�б�
//        }
//    }
//    d[0] = 0;
//    //cout << "p�����ʼΪ" << endl;
//    //for (int i = 0; i < n; i++) {
//    //    cout << p[i] << " ";
//    //}cout << endl;
//    //����
//    for (int r = 0; r < n - 1; r++) {
//        //��һ��û�з��ʹ��ģ����Ҿ���d��̵ĵ�
//        //�����ĳ��ѷ��� ���Ҹ�������graph������d����
//        int index = getmin(d, s);
//        if (index == -1)
//            break; //���н���Ѿ����ʹ��ˣ��˳�ѭ��
//        s[index] = 1;
//        //cout<<"û�з��ʹ�����̵Ľ����"<<index+1<<endl;
//        for (int i = 0; i < n; i++) {
//            if (s[i] == 0 &&graph[index][i]!=INT_MAX&& d[index] + graph[index][i] < d[i]) {
//                d[i] = d[index] + graph[index][i];
//                p[i] = index; //����ǰ���ڵ�  p���ŵ��ǽ���� ��1��ʼ
//            }
//        }
//        //cout<<"p������º�Ϊ"<<endl;
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