#include<bits/stdc++.h>
using namespace std;
const long long  M =133;
const int N =1e5+5;
char str[N];
char num[N];
int  sum[N];
long long cnt[2250005];
int main (){
    scanf("%s",str);
    //getchar();
    scanf("%s",num);
    int k;
    scanf("%d",&k);
    int lennum = strlen(num);
    int lenstr = strlen(str);
    for(int i=1;i<=lenstr;i++){
        sum[i]=sum[i-1]+(((num[(str[i-1]-'a')]-'0')+1)%2);
    }
    int t = 0;
    for(int i=1;i<=lenstr;i++){
            long long tmp = 0;
        for(int j=i;j<=lenstr;j++){
            if(sum[j]-sum[i-1]>k) break;
                tmp = tmp*M+str[j-1];
                cnt[t++] = tmp;
        }
    }

    int n = t;
    sort(cnt,cnt+n);
    int ans = unique(cnt,cnt+n)-cnt;
    printf("%d\n",ans);
    return 0;
}
