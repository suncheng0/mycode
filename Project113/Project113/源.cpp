//广搜只要搜到了终点，那么一定是最短的路径
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>>&graph,vector<bool>&visited,vector<int>&d,int x);
int main(){
    //建图
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
    //连线
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph.size();j++){
            //strlist[i]和strlist[j]只有一个字母不相同 边为1
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
    //广度优先搜索
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
        cout<index<<"访问过了,最短距离"<<di<<endl;
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