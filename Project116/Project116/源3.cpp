//#include<iostream>
//#include<vector>
//using namespace std;
//int find(int i, vector<int>& father);
//bool isSame(int i, int j, vector<int>& father);
//void join(int i, int j, vector<int>& father);
////���޻�ͼ����л�ͼ�����Ǽ���ıߵ������˵㶼��ͬһ�����鼯��
//int main() {
//    //�������
//    int n = 0;
//    cin >> n;//n������ m����
//    int m = n;
//    vector<int>father(n, 0);
//    //��ʼ��father����
//    for (int i = 0; i < n; i++) {
//        father[i] = i;
//    }
//    for (auto k : father)cout << k + 1 << " "; cout << endl;
//    //��������ı����ϲ����鼯
//    while (m--) {
//        int x = 0, y = 0;
//        cin >> x >> y;
//        bool isRongYu = isSame(x - 1, y - 1, father);
//        join(x - 1, y - 1, father);
//        if (isRongYu == true) {
//            //cout<<x<<" "<<y;
//        }
//        for (auto k : father)cout << k + 1 << " "; cout << endl;
//    }
//    return 0;
//}
//int find(int i, vector<int>& father) {
//    if (father[i] == i) {
//        return i;
//    }
//    else {
//        return find(father[i], father);
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
//    int a = find(i, father);//�����˵ĸ���
//    int b = find(j, father);//���ܶ˵ĸ���
//    if (a == b)return;
//    father[b] = a;
//}