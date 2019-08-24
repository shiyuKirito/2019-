#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL k;

int main() {
    while(~scanf("%lld", &k)){
    LL now = 9, cnt = 1;
    while (k > 0) {
        k -= now * cnt;
        now *= 10;
        ++cnt;
    }
    now /= 10;
    cnt--;
    cout<<"K1:"<<k<<endl;
    k += now * cnt;
    cout<<cnt<<endl;
    cout<<k<<endl;
    LL a = (k - 1) / cnt;
    LL b = (k - 1) % cnt + 1;
    cout<<a<<endl;
    cout<<b<<endl;
    if(b==0){
        cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    }
    LL c = 1;
    for (int i = 1; i < cnt; ++i)
    	c *= 10;
    if (b == 0) --a;
    c += a;
    for (LL i = 1; i <= cnt - b; ++i)
        c /= 10;
    printf("%lld", c % 10);
   // return 0;
}
}
