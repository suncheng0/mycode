//#include<iostream>
//#include<vector>
//using namespace std;
//int find(int i, vector<int>& father);
//bool isSame(int i, int j, vector<int>& father);
//void join(int i, int j, vector<int>& father);
////从无环图变成有环图，就是加入的边的两个端点都在同一个并查集里
//int main() {
//    //输入参数
//    int n = 0;
//    cin >> n;//n个顶点 m个边
//    int m = n;
//    vector<int>father(n, 0);
//    //初始化father数组
//    for (int i = 0; i < n; i++) {
//        father[i] = i;
//    }
//    for (auto k : father)cout << k + 1 << " "; cout << endl;
//    //根据输入的边来合并并查集
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
//    int a = find(i, father);//出发端的父亲
//    int b = find(j, father);//接受端的父亲
//    if (a == b)return;
//    father[b] = a;
//}