#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//每个节点的权值为F，给出公式为：F = G + H
//G：起点达到目前遍历节点的距离
//H：目前遍历的节点到达终点的距离
struct Point {
    int x;
    int y;
    int G;
    int H;
};
struct cmp {
    bool operator()(Point a, Point b) {
        return a.H + a.G > b.H + b.G;
    }
};
void Astar(int a1, int a2, int b1, int b2);
int main() {
    int num = 0;
    cin >> num;
    while (num--) {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        Astar(a1-1, a2-1, b1-1, b2-1);
    }
    return 0;
}
vector<vector<int>>move1(1000, vector<int>(1000, 0));//下标从0到999
int dir[8][2] = {-2,1,-2,-1,-1,2,-1,-2,1,2,1,-2,2,1,2,-1};
void Astar(int a1, int a2, int b1, int b2) {
    //自己和自己的距离是0
    priority_queue<Point, vector<Point>, cmp > dui;
    dui.push({ a1,a2,0,0 });
    while (!dui.empty()) {
        Point cur = dui.top();
        int x = cur.x;
        int y = cur.y;
        if (x == b1 && y == b2) {
            break;
        }//cur就是终点，break
        dui.pop();
        //cur就是最合适的下一步
        //把cur相连的，压到堆里
        for (int i = 0; i < 8; i++) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nexty < 0 || nextx > 999 || nexty > 999) {
                continue;
            }
            if (nextx == a1 && nexty == a2) {
                continue;
            }
            if (move1[nextx][nexty] == 0) {
                int G = cur.G+5;
                int H = (nextx - b1) * (nextx - b1) + (nexty - b2) * (nexty - b2);
                int nextstep = move1[x][y] + 1;
                move1[nextx][nexty] = nextstep;
                dui.push({ nextx,nexty,G,H});//下一个值
            }//没有访问过，并且也不是起点
        }
    }
    cout << move1[b1][b2] << endl;
    move1 = vector<vector<int>>(1000, vector<int>(1000, 0));
}