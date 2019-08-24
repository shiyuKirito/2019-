#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
const int maxn=505,maxm=maxn*maxn;

struct Edge{
    int v,f,nxt;
};
int n,src,sink;
int m,p;
int g[maxn+10];
int nume;
Edge e[maxm*2+10];

void addedge(int u,int v,int c){
    e[++nume].v=v;
    e[nume].f=c;
    e[nume].nxt=g[u];
    g[u]=nume;
    e[++nume].v=u;
    e[nume].f=0;
    e[nume].nxt=g[v];
    g[v]=nume;
}

void init(){
    memset(g,0,sizeof(g));
    nume=1;
}

queue<int> que;
bool vis[maxn+10];
int dist[maxn+10];

void bfs(){
    memset(dist,0,sizeof(dist));
    while(!que.empty()) que.pop();
    vis[src]=true;
    que.push(src);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(int i=g[u];i;i=e[i].nxt){
            if(e[i].f&&!vis[e[i].v]){
                que.push(e[i].v);
                dist[e[i].v]=dist[u]+1;
                vis[e[i].v]=true;
            }
        }
    }
}

int dfs(int u,int delta){
    if(u==sink){
        return delta;
    }
    else{
        int ret=0;
        for(int i=g[u];delta&&i;i=e[i].nxt){
            if(e[i].f&&dist[e[i].v]==dist[u]+1){
                int dd=dfs(e[i].v,min(e[i].f,delta));
                e[i].f-=dd;
                e[i^1].f+=dd;
                delta-=dd;
                ret+=dd;
            }
        }
        return ret;
    }
}

int maxflow(){
    int ret=0;
    while(1){
        memset(vis,0,sizeof(vis));
        bfs();
        if(!vis[sink]) return ret;
        ret+=dfs(src,inf);
    }
}

int main(){
    init();
    src=0;
    scanf("%d%d%d",&n,&m,&p);
    sink=n+m+p+1;
    for(int i=0;i<n;i++) addedge(0,i+1,1);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++){
            int tmp;
            scanf("%d",&tmp);
            addedge(i+1,tmp+n,1);
        }
    }
    int check[1005];
    memset(check,0,sizeof(check));
    for(int i=0;i<p;i++){
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++){
            int tmp;
            scanf("%d",&tmp);
            check[tmp-1]=1;
            addedge(tmp+n,i+n+m+1,1);
        }
        int r;
        scanf("%d",&r);
        addedge(i+n+m+1,p+m+n+1,r);
    }
    for(int i=0;i<m;i++){
        if(check[i]==0){
            addedge(i+n+1,n+m+p+1,1);
        }
    }
    printf("%d\n",maxflow());
}
/*
4 3 1
2 1 2
2 1 2
1 3
1 3
2 1 2 1
*/
