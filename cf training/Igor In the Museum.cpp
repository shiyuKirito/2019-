#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
char mm[N][N];
struct node{
  int xx;
  int yy;
  node (int _x,int _y){
    this->xx = _x;
    this->yy = _y;
  }
};
queue<node>qu;
int ans,n,m,k;
int num_visx[N][N];
int num_visy[N][N];
int hash_num[N][N];
bool vis[N][N];
void bfs(int _x,int _y){
    int e_x = _x;
    int e_y = _y;
    vis[_x][_y]=true;
    num_visx[_x][_y] = e_x;
    num_visy[_x][_y] = e_y;
    if(_x+1<=n){
        if(mm[_x+1][_y]=='.'){
            qu.push(node(_x+1,_y));
            vis[_x+1][_y]=true;
            num_visx[_x+1][_y]=e_x;
            num_visy[_x+1][_y]=e_y;
        }
        else{
            ans++;
        }
    }
    if(_y+1<=m){
        if(mm[_x][_y+1]=='.'){
            qu.push(node(_x,_y+1));
            vis[_x][_y+1] = true;
             num_visx[_x][_y+1]=e_x;
             num_visy[_x][_y+1]=e_y;
        }
        else{
            ans++;
        }
    }
    if(_x-1>=1){
        if(mm[_x-1][_y]=='.'){
            qu.push(node(_x-1,_y));
            vis[_x-1][_y]=true;
            num_visx[_x-1][_y]=e_x;
            num_visy[_x-1][_y]=e_y;
        }
        else{
            ans++;
        }
    }
    if(_y-1>=1){
        if(mm[_x][_y-1]=='.'){
            qu.push(node(_x,_y-1));
            vis[_x][_y-1]=true;
            num_visx[_x][_y-1]=e_x;
            num_visy[_x][_y-1]=e_y;
        }
        else{
            ans++;
        }
    }
    while(!qu.empty()){
        node tmp = qu.front();
        qu.pop();
        _x = tmp.xx;
        _y = tmp.yy;
        if(_x+1<=n){
        if(mm[_x+1][_y]=='.'&&vis[_x+1][_y]==false){
            qu.push(node(_x+1,_y));
            vis[_x+1][_y]=true;
            num_visx[_x+1][_y]=e_x;
            num_visy[_x+1][_y]=e_y;
        }
        else{
            if(mm[_x+1][_y]=='*')  ans++;
        }
    }
    if(_y+1<=m){
        if(mm[_x][_y+1]=='.'&&vis[_x][_y+1]==false){
            qu.push(node(_x,_y+1));
            vis[_x][_y+1]=true;
            num_visx[_x][_y+1]=e_x;
           num_visy[_x][_y+1]=e_y;
        }
        else{
           if(mm[_x][_y+1]=='*')  ans++;
        }
    }
    if(_x-1>=1){
        if(mm[_x-1][_y]=='.'&&vis[_x-1][_y]==false){
            qu.push(node(_x-1,_y));
            vis[_x-1][_y]=true;
            num_visx[_x-1][_y]=e_x;
            num_visy[_x-1][_y]=e_y;
        }
        else{
            if(mm[_x-1][_y]=='*') ans++;
        }
    }
    if(_y-1>=1){
        if(mm[_x][_y-1]=='.'&&vis[_x][_y-1]==false){
            qu.push(node(_x,_y-1));
            vis[_x][_y-1] = true;
             num_visx[_x][_y-1]=e_x;
             num_visy[_x][_y-1]=e_y;
        }
        else{
            if(mm[_x][_y-1]=='*') ans++;
        }
    }
    }
        hash_num[e_x][e_y] = ans;
}
int main (){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%s",mm[i]+1);
    }
    /*for(int i=1;i<=n;i++){
        printf("%c\n",mm[i][2]);
    }*/
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        int xxx = num_visx[x][y];
        int yyy = num_visy[x][y];
        if(hash_num[xxx][yyy]){
            printf("%d\n",hash_num[xxx][yyy]);
            continue;
        }
        ans = 0;
        bfs(x,y);
        printf("%d\n",ans);
        ans = 0;
    }
}

