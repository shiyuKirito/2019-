#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int num[N];
int lnum[N];
int rnum[N];
int main (){
    int n;
    scanf("%d",&n);
    int maxl = 0;
    int minr = 0x3f3f3f3f;
    int ltmp=0;
    int rtmp=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&lnum[i],&rnum[i]);
        if(lnum[i]>=maxl){
            if(maxl!=lnum[i]){
                maxl = lnum[i];
                ltmp = i;
            }
            else{
                if(rnum[i]<rnum[ltmp]){
                    ltmp = i;
                }
            }
        }
        if(rnum[i]<=minr){
            if(minr!=rnum[i]){
                minr = rnum[i];
                rtmp = i;
            }
            else{
                if(lnum[i]>lnum[rtmp]){
                  rtmp = i;
                }
            }
        }
    }
    maxl = 0;
    minr = 0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(i==ltmp) continue;
        maxl = max(maxl,lnum[i]);
        minr = min(minr,rnum[i]);
    }
    int ans = minr-maxl;
    //cout<<ans<<endl;
    maxl = 0;
    minr = 0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(i==rtmp) continue;
        maxl = max(maxl,lnum[i]);
        minr = min(minr,rnum[i]);
    }
    ans = max(ans,minr-maxl);
    ans = max(0,ans);
    printf("%d\n",ans);
}

