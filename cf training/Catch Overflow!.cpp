#include<bits/stdc++.h>
using namespace std;
long long  num = (1LL<<32LL)-1LL;
int ss[100005];
int main (){
    //cout<<num<<endl;
    int n;
    scanf("%d",&n);
    long long ans = 0;
    long long cnt =1;
    bool falg = true;
    long long x;
    int t = 0;
    ss[0] = 1;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        if(falg==false) continue;
        if(str=="add"){
            ans+=cnt;
            if(ans>num){
                falg = false;
            }
        }
        else if(str=="for"){
            cin>>x;
            if(cnt>num) {
                ss[++t] = 1;
            }
            else{
                cnt*=x;
                ss[++t] = x;
            }
        }
        else if(str=="end"){
            x = ss[t];
            cnt/=x;
            t--;
        }
    }
    if(falg) cout<<ans<<endl;
    else cout<<"OVERFLOW!!!"<<endl;
}
