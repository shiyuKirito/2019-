#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
const int inf = 0x3f3f3f3f;
char mm[N][N];
int  fyd[N][N];
int  num[1000005];
stack<int>ss;
int ans[1000005];
int main (){
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",mm[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                fyd[i][j]= 0;
                continue;
            }
            if(mm[i][j]=='1'){
                fyd[i][j] = 1;
            }
            else{
                fyd[i][j] = inf;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                fyd[i][j] = min(fyd[i][j],fyd[i][k]+fyd[k][j]);
            }
        }
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&num[i]);
    }
    ss.push(num[1]);
    int dis = 0;
    int t =0;
    for(int i=2;i<=m;i++){
        if(dis+1>fyd[ss.top()][num[i]]){
            ss.push(num[i-1]);
            ans[t++] = ss.top();
            dis = fyd[ss.top()][num[i]];
        }
        else{
            dis++;
        }
    }
    printf("%d\n",t+2);
    printf("%d ",num[1]);
    for(int i=0;i<t;i++){
        printf("%d ",ans[i]);
    }
    printf("%d\n",num[m]);
}
/*
使用floyd算法，通过判断加入点后最短路数值大小。
*/

