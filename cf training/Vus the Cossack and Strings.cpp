#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 2000030;
char a[maxn],b[maxn];
int ans = 0,sum = 0;
int main(){
    scanf("%s",a);
    scanf("%s",b);
    int len_a = strlen(a);
    int len_b = strlen(b);
    for(int i = 0 ; i < len_b ; i++){
        ans=ans^a[i]^b[i];
    }
    cout<<ans<<endl;
    if(ans==0) sum++;
    /*for(int i = len_b ;  i < len_a ; i++){
        ans = ans^a[i-len_b]^a[i];
        if(ans % 2 == 0) sum++;
    }*/
    printf("%d\n",sum);
    return 0;
}


