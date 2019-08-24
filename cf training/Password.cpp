#include<bits/stdc++.h>
using namespace std;
const int N  = 3e6+5;
char str[N];
int jump[N];
void getjump(int sl){
    jump[0] = -1;
    int j = 1;
    int k = -1;
    while(j<=sl){
        while(k==-1||str[j]==str[k+1]){
            jump[j++] = ++k;
        }
        k = jump[k];
    }
}
int cnt[N];
int cnt1[N];
int main (){
    scanf("%s",str+1);
    int sl  =strlen(str+1);
    getjump(sl);
    for(int i=1;i<=sl;i++) cnt1[i] = 1;
    for(int i=sl;i>=0;i--){
        cnt1[jump[i]]+=cnt1[i];
    }
    int ans = 0;
    for(int i=jump[sl];i!=-1;i=jump[i]){
        if(cnt1[i]>=3){
            ans = i;
            break;
        }
    }
    if(ans){
        for(int i=1;i<=ans;i++){
            printf("%c",str[i]);
        }
    }
    else{
        printf("Just a legend\n");
    }
    return 0;
}
