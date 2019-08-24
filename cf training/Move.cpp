#include <bits/stdc++.h>
using namespace std;
int a[1005],vis[1005];
int n,k;
bool check(int mid){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=k;i++){
        int tmp=mid;
        for(int j=n;j>=1;j--){
            if(!vis[j]&&a[j]<=tmp){
                tmp-=a[j];
                vis[j]=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) return false;
    }
    return true;
}

int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sort(a+1,a+1+n);
        if(n<=k){
            printf("Case #%d: %d\n",++cas,a[n]);
            continue;
        }
        int ans=0;
        int l=ceil(sum/k),r=0x3f3f3f3f;
        for(int i=l;i<=r;i++){
            if(check(i)){
                ans=i;
                break;
            }
        }
        //int ans=l;
        printf("Case #%d: %d\n",++cas,ans);
    }
}
