#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int num[N];
int ss[N];
vector<int>vv[N];
int main (){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    int cnt = 0;
    ss[0] = num[1];
    vv[0].push_back(num[1]);
    for(int i=2;i<=n;i++){
        int tmp = ss[cnt];
        if(num[i]<tmp){
            ss[++cnt] = num[i];
            vv[cnt].push_back(num[i]);
        }
        else{
            for(int j=0;j<=cnt;j++){
               int tmp =ss[j];
               if(num[i]>tmp){
                 ss[j]=num[i];
                 vv[j].push_back(num[i]);
                 break;
               }
            }
        }
    }
    for(int i=0;i<=cnt;i++){
        for(vector<int>::iterator j=vv[i].begin();j!=vv[i].end();j++){
            printf("%d ",*j);
        }
        printf("\n");
    }
    return 0;
}

