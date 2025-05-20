#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
using namespace std;
// �Ͻ�˹����
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
    };//���վ����С����
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        // �����黯��ͼ ����m*n�����
        // ÿ�������һ��ָ���ұߺ�����ĵ���ߣ�����Ϊ1
        // �±�Ϊk�Ķ����������k+m��������k+1
        // �±�Ϊm-1�ı����Ķ���û������
        // �±���ڵ���m*(n-1)�Ķ���û������
        // �ڸ��µϽ�˹�����Ķ������·����ʱ�䣩��ʱ��������·��С�ڽڵ��movetumeֵ������movetumeֵ
        vector<int>dis(n * m, MAXNUM);//n*m�񶥵�
        vector<list<Edge>>linjie(n * m);
        for (int i = 0; i < n * m; i++) {  // ����ÿһ�����
            if (i == 0 || (i - m + 1) % m != 0) { // ������
                linjie[i].push_front({ i + 1,1 });
            }
            if (i < m * (n - 1)) { // ������
                linjie[i].push_front({ i + m,1 });
            }
            if (i % m != 0) {//�����
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
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>dui;//pair<����ţ����ڵ�ľ���>
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
            for (auto edge : linjie[vex]) {//����ÿ���͸ýڵ����ڵı�
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
