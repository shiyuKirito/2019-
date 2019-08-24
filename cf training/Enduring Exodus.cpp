#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
char ch[N];
int st[N];
int main (){
    int n,k;
    scanf("%d%d",&n,&k);
    getchar();
    int t = 0;
    for(int i=0;i<n;i++){
        scanf("%c",&ch[i]);
        if(ch[i]=='0'){
            st[t++] = i;
        }
    }
    int ans = n;
    for(int i=0;i<t-k;i++){
        int ss = st[i+k]-st[i];
        ss/=2;
        ss+=st[i];
        int x = lower_bound(st+i,st+i+k,ss)-st;
        ans = min(ans,max(st[x]-st[i],st[i+k]-st[x]));
        ans = min(ans,max(st[x-1]-st[i],st[i+k]-st[x-1]));
    }
    printf("%d\n",ans);
    return 0;
}
