#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
map<int,int>mm;
int num[maxn];
int main (){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    sort(num+1,num+1+n);
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(num[i]%k!=0||(!mm[num[i]/k])){
             ans ++;
            mm[num[i]] = 1;
        }
    }
    printf("%d\n",ans);
}
