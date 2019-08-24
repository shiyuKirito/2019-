#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5+5;
multiset<int>vvm;
vector<int>vv;
priority_queue<int>q;
set<int>ss;
int num[maxn];
int vis[maxn];
int _find(int x){
    return lower_bound(vv.begin(),vv.end(),x)-vv.begin();
}
int main (){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        vv.push_back(num[i]);
    }
    sort(vv.begin(),vv.end());
    vv.erase(unique(vv.begin(),vv.end()),vv.end());
    for(int i=1;i<=k;i++){
        int p =_find(num[i]);
        vis[p]++;
        if(vis[p]==1) q.push(p);
    }
    while((!q.empty())&&vis[q.top()]!=1) q.pop();
    if(q.empty()) {
            printf("Nothing\n");
    }
    else{
        printf("%d\n",vv[q.top()]);
    }
        int j = k+1;
        for(int i=1,j=k+1;j<=n;){
            int p1=_find(num[i]);
            int p2=_find(num[j]);
            --vis[p1];
            ++vis[p2];
           // cout<<'~'<<vis[p1]<<endl;
            //cout<<'-'<<vis[p2]<<endl;
            if(vis[p1]==1) {
                    q.push(p1);
            }
            if(vis[p2]==1) q.push(p2);
            while((!q.empty())&&vis[q.top()]!=1) q.pop();
            if(q.empty()) {
                    printf("Nothing\n");
                    i++;
                    j++;
                    continue;
            }
            printf("%d\n",vv[q.top()]);
            i++;
            j++;
    }
        return 0;
    }
close