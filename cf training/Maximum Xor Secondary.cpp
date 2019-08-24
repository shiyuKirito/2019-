#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+30;
int mx1,mx2;
void work(int x){
    if(x>mx2){
        if(x>mx1){
            mx2 = mx1;
            mx1 = x;
            return ;
        }
        mx2 = x;
    }
}
stack<int>ss1;
stack<int>ss2;
int num[maxn];
int main(){
    int n;
    scanf("%d",&n);
    int ans = 0;
    int max_num;
    int min_num =0x3f3f3f3f;
    for(int i=1;i<=n;i++) {
            scanf("%d",&num[i]);
    }
    for(int i=1;i<=n;i++){
        while(!ss1.empty()&&num[ss1.top()]<num[i]) {
               //ans = max(ans,num[ss1.top()]^num[i]);
                ss1.pop();
        }
        if(!ss1.empty()) {
                ans = max(ans,num[ss1.top()]^num[i]);
        }
        ss1.push(i);
    }
    while(!ss1.empty()){
         ss1.pop();
    }
    for(int i=n;i>=1;i--){
        while(!ss2.empty()&&num[ss2.top()]<num[i]) {
               // ans = max(ans,num[ss1.top()]^num[i]);
                ss2.pop();
        }
        if(!ss2.empty()) {
                ans = max(ans,num[ss2.top()]^num[i]);
        }
        ss2.push(i);
    }
 
   // ss1.clear();
    // 5
    // 9 8 3 5 7
    // 5
    // 1 2 3 4 5
    // 5 4 3 2 1
    /*
    9 8
    9 8 3
    9 8 5
    9 8 7
    */
    printf("%d\n",ans);
    return 0;
}