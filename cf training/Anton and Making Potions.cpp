#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 2e5+5;
LL a[N],b[N],c[N],d[N];
int main (){
    LL ans = 0;
    LL  n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    LL x,s;
    scanf("%lld%lld",&x,&s);
    ans = x*n;
    for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
    for(int i=1;i<=k;i++) scanf("%lld",&c[i]);
    for(int i=1;i<=k;i++) scanf("%lld",&d[i]);
    a[0] =x;
    for(int i=0;i<=m;i++){
        if(s>=b[i]){
            int pos = upper_bound(d+1,d+k+1,s-b[i])-d;
            ans=min(((n-c[pos-1])*a[i]),ans);
            if(ans<=0){
                ans = 0;
            }
        }
    }
    printf("%lld\n",ans);
}
