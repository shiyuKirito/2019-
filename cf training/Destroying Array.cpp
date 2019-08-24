#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5+5;
LL num[maxn];
bool vis[maxn];
int ss[maxn];
LL ans[maxn];
int pre[maxn];
LL sum[maxn];
int _find (int x){
    if(pre[x] == x) return x;
    return pre[x]=_find(pre[x]);
}
void join(int _x,int _y ,LL *_sum){
    int xx = _find(pre[_x]);
    int yy = _find(pre[_y]);
    _sum[yy]+=_sum[xx];
    pre[xx] =yy;//sum[yy]+=sum[xx];
}
int main (){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ss[i]);
        pre[i] = i;
    }
   // pre[0] = 0;
    //pre[n+1] = 0;
     //int ans = 0;
    ans[n] = 0;
    sum[ss[n]] = num[ss[n]];
    vis[ss[n]]=true;
     //cout<<sum[ss[n]]<<endl;
    for(int i=n;i>1;i--){
        //printf("%d\n",ans);
        int tmp = ss[i];
        sum[tmp] = num[tmp];
        vis[tmp]=true;
        if(tmp>1&&vis[tmp-1]){
            join(tmp-1,tmp,sum);
        }
        //ans[i-1] = max(ans[i-1],max(ans[i],sum[_find(tmp)]));
        //cout<<"ans[i]"<<ans[i]<<endl;
        //cout<<sum[_find(tmp)]<<endl;
        if(tmp<n&&vis[tmp+1]){
            join(tmp,tmp+1,sum);
        }
        ans[i-1] = max(ans[i-1],max(ans[i],sum[_find(tmp)]));
    }
    for(int i=1;i<=n;i++){
        printf("%lld\n",ans[i]);
    }
}
