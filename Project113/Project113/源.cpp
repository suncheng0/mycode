//����ֻҪ�ѵ����յ㣬��ôһ������̵�·��
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>>&graph,vector<bool>&visited,vector<int>&d,int x);
int main(){
    //��ͼ
    int n=0;
    cin>>n;
    vector<bool>visited(n+2);
    vector<int>d(n+2);
    vector<vector<int>>graph(n+2,vector<int>(n+2,0));
    vector<string>strlist(n+2,"");
    cin>>strlist[0]>>strlist.back();
    for(int i=1;i<=n;i++){
        cin>>strlist[i];
    }
    //����
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph.size();j++){
            //strlist[i]��strlist[j]ֻ��һ����ĸ����ͬ ��Ϊ1
            int k=strlist[i].size();
            int nos=0;
            while(k--){
                if(strlist[i][k]!=strlist[j][k]){
                    nos++;
                }
            }
            if(nos==1){
                graph[i][j]=1;
            }
        }
    }
    // for(auto k:graph){
    //     for(auto kk:k){
    //         cout<<kk<<" ";
    //     }
    //     cout<<endl;
    // }
    //�����������
    bfs(graph,visited,d,0);
    cout<<d.back();
    return 0;
}
int max_path=0,path=0;
void bfs(vector<vector<int>>&graph,vector<bool>&visited,vector<int>&d,int x){
    queue<int>q;
    q.push(x);
    d[0]=1;
    while(!q.empty()){
        int index=q.front();
        int di=d[index];
        visited[index]=1;
        cout<index<<"���ʹ���,��̾���"<<di<<endl;
        q.pop();
        for(int i=0;i<graph[0].size();i++){
            if(visited[i]==0&&graph[index][i]==1){
                q.push(i);
                d[i]=di+1;
            }
        }
    }
}
//6
//hit cog
//hot
//dot
//dog
//lot
//log
//cog