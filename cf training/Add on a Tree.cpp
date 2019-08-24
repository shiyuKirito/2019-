#include<bits/stdc++.h>
using namespace std;
const int maxn =1e5+5;
vector<int>a[maxn];
int main (){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
   // bool falg =true;
    for(int i=1;i<=n;i++){
        if(a[i].size()==2){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    /*if(falg){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }*/
    return 0;
}
