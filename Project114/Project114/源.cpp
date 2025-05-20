//#include<iostream>
//#include<vector>
//using namespace std;
//int find(int i, vector<int>& father);
//bool isSame(int i, int j, vector<int>& father);
//void join(int i, int j, vector<int>& father);
//int main() {
//    //输入参数
//    int n = 0, m = 0;
//    cin >> n >> m;//n个顶点 m个边
//    vector<int>father(n, 0);
//    //初始化father数组
//    for (int i = 0; i < n; i++) {
//        father[i] = i;
//    }
//    //for(auto k:father)cout<<k+1<<" ";cout<<endl;
//    //根据输入的边来合并并查集
//    while (m--) {
//        int x = 0, y = 0;
//        cin >> x >> y;
//        join(x - 1, y - 1, father);
//        //for(auto k:father)cout<<k+1<<" ";cout<<endl;
//    }
//    //
//    int x = 0, y = 0;
//    cin >> x >> y;
//    //
//    //for(auto k:father)cout<<k<<" ";
//    cout << isSame(x - 1, y - 1, father);
//    return 0;
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
//    if (find[i] == find[j]) {
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