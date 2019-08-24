#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf=0x3f3f3f3f3f3f3f3f;

string s;
int n;

int fc(string a){
    int cnt=0;
    int pos=0;
    while(1){
        int tmp=s.find(a,pos);
        if(tmp==-1) return cnt;
        cnt++;
        pos=tmp+a.length();
    }
}

int main(){
    cin>>s;
    n=s.length();
    int ans=n;
    for(int i=1;i<=n;i++){
        for(int j=0;j+i<=n;j++){
            string tmp=s.substr(j,i);
            int k=fc(tmp);
            if(k!=0) ans=min(ans,n+k-(k-1)*i);
        }
    }
    printf("%d\n",ans);
}
