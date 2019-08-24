#include<bits/stdc++.h>
using namespace std;
char ch[1005][1005];
int cnt[1005][1005];
int main (){
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
   for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(ch[i][j]==ch[i+1][j]) cnt[i][j]=cnt[i+1][j]+1;
            else cnt[i][j] = 1;
        }
   }
   int ta = 0;
   int ans =0;
   int tmp =0;
   for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        int th = cnt[i][j];
        if(i+3*th-1>n||
           cnt[i+th][j]!=th||
           ch[i+th][j]==ch[i][j]||
           ch[i+th][j]==ch[i+2*th][j]||
           cnt[i+2*th][j]<th){
            ta = 0;
            continue;
        }
        else{
            if(ta&&ch[i][j]==ch[i][j-1]&&
               cnt[i][j-1]==th&&
               cnt[i+th][j-1]==th&&
               cnt[i+2*th][j-1]>=th&&
               ch[i+th][j]==ch[i+th][j-1]&&
               ch[i+2*th][j]==ch[i+2*th][j-1]){
                ta++;
            }
            else{
                ta = 1;
            }
        }
        ans+=ta;
    }
    ta = 0;
   }
   printf("%d\n",ans);
}
