////prim��С������
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//typedef struct {
//    int begin;
//    int end;
//    int weight;
//}edge;
//void kruskal(vector<edge>& arc, vector<int>& father, int& ans);
//int find(int i, vector<int>& father);
//bool isSame(int i, int j, vector<int>& father);
//void join(int i, int j, vector<int>& father);
//
//int main() {
//    //��ͼ
//    int v = 0, e = 0;
//    cin >> v >> e;
//    vector<vector<int>>graph(v, vector<int>(v, 0));
//    vector<int>father(v);
//    vector<edge>arc;
//    while (e--) {
//        int x = 0, y = 0, val = 0;
//        cin >> x >> y >> val;
//        edge bian = { x - 1,y - 1,val };
//        arc.push_back(bian);
//    }
//    for (int i = 0; i < father.size(); i++) {
//        father[i] = i;
//    }
//    //�Ա߽�������
//    sort(arc.begin(), arc.end(), [&](const edge& a, const edge& b) {
//        return a.weight < b.weight;
//        });
//    int ans = 0;
//    //kruskal
//    kruskal(arc, father, ans);
//    cout << ans;
//    return 0;
//}
//void kruskal(vector<edge>& arc, vector<int>& father, int& ans) {
//    //�ѱ߰��մ�С��������
//    //ѡ��һ����̵ı�
//    //�������ߵ������յ��ǲ�����ͬһ�����鼯��
//    //����ڣ����� ����һ����
//    //������ڣ��������߼��뵽��� �������ߵ������յ�Ĳ��鼯�ϲ�
//    for (int i = 0; i < arc.size(); i++) {
//        if (find(arc[i].begin, father) == find(arc[i].end, father)) {
//            continue;
//        }
//        else {
//            ans += arc[i].weight;
//            join(arc[i].begin, arc[i].end, father);
//        }
//    }
//}
//int find(int i, vector<int>& father) {
//    if (father[i] == i) {
//        return i;
//    }
//    else {
//        return father[i] = find(father[i], father);
//    }
//}
//bool isSame(int i, int j, vector<int>& father) {
//    if (find(i, father) == find(j, father)) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}
//void join(int i, int j, vector<int>& father) {
//    int a = find(i, father);
//    int b = find(j, father);
//    if (a == b)return;
//    father[a] = b;
//}