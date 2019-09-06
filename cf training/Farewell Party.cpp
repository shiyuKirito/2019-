#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int vis[N];
int ans[N];
int num[N];
int hash_num[N];
bool falg = true;
int main (){
    int n;
    scanf("%d",&n);
    int cnt = 1;
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        if(vis[num[i]]){
            ans[i] = vis[num[i]];
        }
        else{
            vis[num[i]] = cnt++;
            ans[i] = vis[num[i]];
        }
        hash_num[ans[i]]++;
        if(hash_num[ans[i]]==(n-num[i])){
            vis[num[i]]=0;
        }
    }
    for(int i=0;i<n;i++){
        int tmp = n-hash_num[ans[i]];
        if(num[i]!=tmp){
            falg = false;
            break;
        }
    }
    if(falg){
        printf("Possible\n");
        for(int i=0;i<n;i++){
            printf("%d ",ans[i]);
        }
    }
    else{
        printf("Impossible\n");
    }
}
