#include<bits/stdc++.h>
using namespace std;
struct node
{
     int num;
     int mm;
};
node a[200005];
bool cmp(node x, node y){
    return  x.num<y.num;
}
set<int>ss;
set<int>ans;
set<int>ans1;
set<int>ju;
set<int>ans_ok;
int main (){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i].num;
        a[i].mm = i+1;
    }
    sort(a,a+n,cmp);
    for(int i=1; i<n; i++){
        int tmp =a[i].num - a[i-1].num;
        ss.insert(tmp);
    }
    if(ss.size()==1){
        cout<<a[0].mm<<endl;
        return 0;
    }
    if(ss.size()>3){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=2;i<n; i++){
        int tmp =a[i].num-a[i-1].num;
        ans.insert(tmp);
    }
    if(ans.size()==1){
        cout<<a[0].mm<<endl;
        return 0;
    }
    for(int i=1;i<n-1;i++){
        int tmp = a[i].num-a[i-1].num;
        ans1.insert(tmp);
    }
    if(ans1.size()==1){
        cout<<a[n-1].mm<<endl;
        return 0;
    }
    ans_ok.insert(a[2].num-a[0].num);
    for(int i=3;i<n;i++){
        int tmp =a[i].num-a[i-1].num;
        ans_ok.insert(tmp);
    }
    if(ans_ok.size()==1){
        cout<<a[1].mm<<endl;
        return 0;
    }
    int t_num = a[1].num - a[0].num;
    int f_m =1;
    for(int i=1;i<n;i++){
        if(a[i].num-a[i-1].num==t_num) continue;
        else{
            f_m = a[i].mm;
            break;
        }
    }
    for(int i=1;i<n;i++){
            int tmp ;
        if(a[i].mm==f_m){
            i++;
            tmp = a[i].num - a[i-2].num;
        }
        else{
            tmp = a[i].num-a[i-1].num;
        }
        ju.insert(tmp);
    }
    if(ju.size()==1){
        cout<<f_m<<endl;
        return 0;
    }
    else{
        cout<<-1<<endl;
    }
}
