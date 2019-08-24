#include<bits/stdc++.h>
using namespace std;
const int N = 1e+5;
int jump[N],ans[N], dp[N];
char str[N];
void getinit(){
    int sl = strlen(str+1);
        int k=0;
    for(int i=2;i<=sl;i++){
        while(k&&str[i]!=str[k+1]){
            k = jump[k];
        }
        if(str[i]==str[k+1]){
            k++;
        }
        jump[i] = k;
    }
}
int main (){
    int t = 0;
    scanf("%s",str+1);
    getinit();
    int sl = strlen(str+1);
    for(int i=jump[sl];i;i=jump[i]){
        ans[t++] = i;
    }
    for(int i=sl;i>=1;i--){
        dp[i]++;
        dp[jump[i]]=dp[jump[i]]+dp[i];
    }
    printf("%d\n",t+1);
    for(int i=t-1;i>=0;i--){
        printf("%d %d\n",ans[i],dp[i]);
    }
    printf("%d %d\n",sl,1);
}
