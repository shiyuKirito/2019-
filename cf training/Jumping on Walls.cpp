#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
char ch[2][N];
int vis[2][N][4];
int n,k;
bool falg = false;
void dfs(int id,int x,int len,int div){
    if(falg) return;
    if(x<=len) return;
    if(x<=0) return;
    if(ch[id][x]=='X') return;
    if(vis[id][x][div]) return;
    vis[id][x][div] = 1;
    if(x>=n){
        falg = true;
        return;
    }
    dfs((id+1)%2,x+k,len+1,2);
    dfs(id,x+1,len+1,0);
    dfs(id,x-1,len+1,1);
}
int main (){
    scanf("%d%d",&n,&k);
    getchar();
    for(int i=1;i<=n;i++) scanf("%c",&ch[0][i]);
    getchar();
    for(int i=1;i<=n;i++) scanf("%c",&ch[1][i]);
    dfs(0,1,0,3);
    if(falg) printf("YES\n");
    else  printf("NO\n");
    return 0;
}
