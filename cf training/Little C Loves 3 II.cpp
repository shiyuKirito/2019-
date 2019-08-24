#include<bits/stdc++.h>
using namespace std;
int main (){
    long long  n,m;
    scanf("%lld%lld",&n,&m);
    long long  s1 = n/6, s1m = n%6;
    long long s2 = m/6, s2m = m%6;
    long long ans = 0;
    if(n%6==0||m%6==0){
        ans = n*m;
        printf("%lld\n",ans);
        return 0;
    }
    ans = (n*m)-(s1m*s2m);
    if(s1m==1){
        if(s2m==1){
            ans +=0;
        }
        else if(s2m==2){
            ans+=0;
        }
        else if(s2m==3){
            ans+=0;
        }
        else if(s2m==4){
            ans+=2;
        }
        else if(s2m==5){
            ans+=4;
        }
    }
    else if(s1m==2){
        if(s2m==1){
            ans+=0;
        }
        else if(s2m==2){
            ans+=0;
        }
        else if(s2m==3){
            ans+=4;
        }
        else if(s2m==4){
            ans+=8;
        }
        else if(s2m==5){
            ans+=10;
        }
    }
    else if(s1m==3){
        if(s2m==1){
            ans+=0;
        }
        else if(s2m==2){
            ans+=4;
        }
        else if(s2m==3){
            ans+=8;
        }
        else if(s2m==4){
            ans+=12;
        }
        else if(s2m==5){
            ans+=14;
        }
    }
    else if(s1m==4){
        if(s2m==1){
            ans+=2;
        }
        else if(s2m==2){
            ans+=8;
        }
        else if(s2m==3){
            ans+=12;
        }
        else if(s2m==4){
            ans+=16;
        }
        else if(s2m==5){
            ans+=20;
        }
    }
    else if(s1m==5){
        if(s2m==1){
            ans+=4;
        }
        else if(s2m==2){
            ans+=10;
        }
        else if(s2m==3){
            ans+=14;
        }
        else if(s2m==4){
            ans+=20;
        }
        else if(s2m==5){
            ans+=24;
        }
    }
    if(min(n,m)>=2&&max(n,m)>6) ans = max(ans,(n*m)/2*2);
    if(min(n,m)==2&&max(n,m)==7) ans = 12;
    printf("%lld\n",ans);
    return 0;
}
