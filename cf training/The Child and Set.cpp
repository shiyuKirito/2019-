#include<bits/stdc++.h>
using namespace std;
const int N  =1e5+5;
struct node{
   int id;
   int ss;
};
node num[N];
int ans[N];
bool cmp(node x,node y){
   return x.ss>y.ss;
}
int lowbit(int x){
  return x&(-x);
}
//4 6 8 ----> 10
int main (){
  int n ,m;
  scanf("%d%d",&n,&m);
  /*for(int i=1;i<=100;i++){
    cout<<i<<": "<<lowbit(i)<<" ";
    if(i%4==0) cout<<endl;
  }
  cout<<endl;*/
  for(int i=1;i<=m;i++){
      num[i].id = i;
      num[i].ss = lowbit(i);
  }
  int sum  =  0;
  int t = 0;
  sort(num+1,num+1+n,cmp);
  for(int i=1;i<=m;i++){
      if(sum+num[i].ss<=n){
        sum+=num[i].ss;
        ans[++t] = num[i].id;
      }
      if(sum==n) {
        break;
      }
  }
  if(sum==n){
      printf("%d\n",t);
      for(int i=1;i<=t;i++){
        printf("%d ",ans[i]);
      }
  }
  else{
    printf("-1\n");
  }
}