//拓扑排序
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void topologic(vector<int>& rudu, vector<vector<int>>& graph);
int main() {
    //建图
    int n = 0, m = 0;
    cin >> n >> m;//n个顶点 m条边
    vector<vector<int>>graph(n, vector<int>(n));
    while (m--) {
        int x = 0, y = 0;
        cin >> x >> y;
        graph[x][y] = 1;//x->y
    }
    //拓扑排序
    vector<int>rudu(n, 0);//入度
    for (int j = 0; j < graph[0].size(); j++) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i][j] == 1) {
                rudu[j]++;
            }
        }
    }
    //每次遍历一边入度表 将入度为0的顶点压入栈
    //从栈顶拿一个元素放入结果 根据该元素更新入度表
    //栈空 结束
    topologic(rudu, graph);
    return 0;
}
void topologic(vector<int>& rudu, vector<vector<int>>& graph) {
    stack<int>s;
    vector<int>ans;
    vector<bool>visited(rudu.size(), false);
    for (int i = 0; i < rudu.size(); i++) {
        if (rudu[i] == 0 && visited[i] == 0) {
            s.push(i);
            visited[i] = 1;
        }
    }
    while (!s.empty()) {
        int x = s.top();
        ans.push_back(x);
        s.pop();
        for (int i = 0; i < graph.size(); i++) {
            if (graph[x][i] == 1) {
                rudu[i]--;
            }
        }
        for (int i = 0; i < rudu.size(); i++) {
            if (rudu[i] == 0 && visited[i] == 0) {
                s.push(i);
                visited[i] = 1;
            }
        }
    }
    for (auto k : ans)cout << k << " ";
}