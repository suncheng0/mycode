//��������
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void topologic(vector<int>& rudu, vector<vector<int>>& graph);
int main() {
    //��ͼ
    int n = 0, m = 0;
    cin >> n >> m;//n������ m����
    vector<vector<int>>graph(n, vector<int>(n));
    while (m--) {
        int x = 0, y = 0;
        cin >> x >> y;
        graph[x][y] = 1;//x->y
    }
    //��������
    vector<int>rudu(n, 0);//���
    for (int j = 0; j < graph[0].size(); j++) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i][j] == 1) {
                rudu[j]++;
            }
        }
    }
    //ÿ�α���һ����ȱ� �����Ϊ0�Ķ���ѹ��ջ
    //��ջ����һ��Ԫ�ط����� ���ݸ�Ԫ�ظ�����ȱ�
    //ջ�� ����
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