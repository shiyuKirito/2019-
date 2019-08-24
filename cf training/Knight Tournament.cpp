#include<bits/stdc++.h>
using namespace std;
const int N =3e5+5;
int vis[N];
int  ans[N];
int cnt[N];
int main (){
    int n,m;
    scanf("%d%d",&n,&m);
    ans[0] = 1;
    for(int i=1;i<=m;i++){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        for(int j=l;j<=r;j++){
          if(vis[j]>=r&&vis[r]){
                break;
           }
           if(j==x) {
                continue;
           }
           if(vis[j]){
               int tmp = j;
                if(j!=vis[j]){
                    j = vis[j];
                    j--;
                }
                if(tmp>x) vis[tmp] = r+1;
                else{
                    vis[tmp] = x;
                }
                continue;
           }
           if(j>x)   vis[j] = r+1;
           else{
              vis[j] = x;
           }
           if(ans[j]==0){
                ans[j] =x;
           }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
}

