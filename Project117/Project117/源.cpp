#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;
// 迪杰斯特拉
struct Edge {
    int to;
    int weight;
    Edge(int x, int y) :to(x), weight(y) {}
};
class Solution {
public:
    const int MAXNUM = 100000;
    struct cmp {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        }
    };//按照距离大小排序
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        // 把数组化成图 共有m*n个结点
        // 每个结点有一条指向右边和下面的单向边，长度为1
        // 下标为k的顶点的下面是k+m，右面是k+1
        // 下标为m-1的倍数的顶点没有右面
        // 下标大于等于m*(n-1)的顶点没有下面
        // 在更新迪杰斯特拉的顶点最短路径（时间）的时候，如果最短路径小于节点的movetume值，就是movetume值
        vector<int>dis(n * m, MAXNUM);//n*m格顶点
        vector<list<Edge>>linjie(n * m);
        for (int i = 0; i < n * m; i++) {  // 遍历每一个结点
            if (i == 0 || (i - m + 1) % m != 0) { // 有右面
                linjie[i].push_front({ i + 1,1 });
            }
            if (i < m * (n - 1)) { // 有下面
                linjie[i].push_front({ i + m,1 });
            }
            if (i % m != 0) {//有左边
                linjie[i].push_front({ i - 1,1 });
            }
            if (i / m != 0) {
                linjie[i].push_front({ i - m,1 });
            }
        }
        // dijkstra
        int ans = dijkstra(moveTime, linjie, dis);
        return ans;
    }
    int dijkstra(vector<vector<int>>& moveTime, vector<list<Edge>>& linjie, vector<int>& dis) {
        int vexnum = dis.size();
        vector<bool>visited(vexnum);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>dui;//pair<结点编号，到节点的距离>
        dui.push(pair<int, int>(0, 0));
        while (!dui.empty()) {
            pair<int, int>cur = dui.top();
            dui.pop();
            int vex = cur.first;
            int d = cur.second;
            if (visited[vex] == 1) {
                continue;
            }
            visited[vex] = 1;
            dis[vex] = d;
            for (auto edge : linjie[vex]) {//遍历每个和该节点相邻的边
                if (visited[edge.to] == 0 && d + edge.weight < dis[edge.to]) {
                    dui.push({ edge.to,d + edge.weight });
                }
            }
        }
        return dis.back();
    }
};
int main()
{
    vector<vector<int>>moveTime = { {0,4},{4,4} };
    Solution s;
    cout<<s.minTimeToReach(moveTime);
	return 0;
}
