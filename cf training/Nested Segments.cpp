#include<bits/stdc++.h>
using namespace std;
const int N = 3*1e5+5;
struct node{
  int l;
  int r;
  int id;
};
node ss[N];
int sum[N];
int ans[N];
 int lowbit(int x){
  return  x&(-1*x);
}
void update(int x,int n){
    while(x<=n){
        sum[x]++;
        x+=lowbit(x);
    }
}
int query(int x,int n){
    int s = 0;
    while(x>0){
        s+=sum[x];
        x-=lowbit(x);
    }
    return s;
}
bool cmp1(node a, node b){
    if(a.r==b.r)  return a.l<=b.l;
    return a.r<b.r;
}
bool cmp2(node a, node b){
    if(a.l==b.l) return a.r <= b.r;
    return a.l>b.l;
}
int main (){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        ss[i].l = a;
        ss[i].r = b;
        ss[i].id = i;
    }
    sort(ss+1,ss+1+n,cmp1);
    for(int i=1;i<=n;i++){
        ss[i].r = i;
    }
    sort(ss+1,ss+1+n,cmp2);
    for(int i=1;i<=n;i++){
        ans[ss[i].id] = query(ss[i].r,n);
        update(ss[i].r,n);
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
}
