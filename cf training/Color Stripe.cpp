#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 5e5+5;
char num[maxn];
char ch[30];
int main (){
    int n,k;
    scanf("%d%d",&n,&k);
    getchar();
    for(int i=1;i<=n;i++) scanf("%c",&num[i]);
    for(int i=1;i<=k;i++) ch[i] =(char)((int)'A'+i-1);
    int ans = 0;
    if(k==2){
            int cnt =0;
        for(int i=1;i<=n;i++){
            if(num[i]==('A'+(i-1)%2)){
                cnt++;
            }
        }
            ans = min(cnt,n-cnt);
            for(int i=1;i<=n;i++){
                if(cnt == ans){
                    num[i] = 'A' + i%2;
                }
                else{
                    num[i] = 'A' + (i-1)%2;
                }
            }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++){
            printf("%c",num[i]);
        }
        return 0;
    }
    for(int i=2;i<=n-1;i++){
        if(num[i]==num[i-1]&&num[i]==num[i+1]){
            ans++;
            int getnum = (int)num[i]-(int)'A'+1;
            if(getnum==k){
                getnum = k-1;
                num[i] = ch[getnum];
                continue;
            }
            getnum = getnum+1;
            num[i] = ch[getnum];
        }
    }
    int ss = 0;
   for(int i=2;i<=n;i++){
        if(i-2>0){
            ss = (int)num[i-2]-(int)'A'+1;;
            if(num[i]==num[i-1]){
                ans++;
                int getnum = (int)num[i]-(int)'A'+1;
                if(max(getnum,ss)-min(getnum,ss)>1){
                    getnum = min(getnum,ss)+1;
                    num[i-1] = ch[getnum];
                    continue;
                }
                if(min(getnum,ss)>1){
                    getnum = min(getnum,ss)-1;
                    num[i-1]=ch[getnum];
                    continue;
                }
                if(max(getnum,ss)==k){
                    num[i]=ch[ss];
                    continue;
                }
                getnum = max(getnum,ss)+1;
                num[i-1] = ch[getnum];
            }
      }
      else{
        if(num[i]==num[i-1]){
                ans++;
            int getnum = (int)num[i]-(int)'A'+1;
            if(getnum==k){
                getnum = k-1;
                num[i-1] = ch[getnum];
                continue;
            }
            getnum = getnum+1;
            num[i-1] = ch[getnum];
        }
      }
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        printf("%c",num[i]);
    }
}
