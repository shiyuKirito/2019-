#include<bits/stdc++.h>
using namespace std;
string na[15];
string str;
queue<int> q1,q2,q3;
vector<int> v1,v2;
int t[2][15];
void addtime(queue<int> tmp,int key){
    while(!tmp.empty()){
        t[key][tmp.front()]++;
        tmp.pop();
    }
}
void show(queue<int> tmp,int key){
    int a[5];
    int cnt=0;
    while(!tmp.empty()){
        a[cnt]=tmp.front();
        cnt++;
        tmp.pop();
    }
    //cout<<t[key][a[0]]<<" "<<t[key][a[1]]<<endl;
    if(t[key][a[0]]<t[key][a[1]]){
        swap(a[0],a[1]);
    }
    for(int i=0;i<2;i++){
        cout<<na[a[i]]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>na[i];
    }
    cin>>str;
    q1.push(3); q1.push(1);
    q2.push(4); q2.push(2);
    t[0][1]=t[1][2]=2; t[0][3]=t[1][4]=1;
    //t[0][3]=t[0][1]=t[1][4]=t[1][2]=1;
    for(int i=5;i<=n;i++){
        q3.push(i);
    }
    int len=str.size();
    int ans1,ans2,cnt;
    ans1=ans2=cnt=0;
    char tmp=str[0];
    for(int i=0;i<len;i++){
        if(tmp==str[i]){
            cnt++;
        }
        else{
            if(tmp=='W'){
                ans1=max(ans1,cnt);
            }
            else{
                ans2=max(ans2,cnt);
            }
            tmp=str[i];
            cnt=1;
        }
    }
    if(tmp=='W'){
        ans1=max(ans1,cnt);
    }
    else{
        ans2=max(ans2,cnt);
    }
    ans1=max(ans1,ans2);
    tmp=str[0];
    cnt=0;
    for(int i=0;i<len;i++){
        if(tmp==str[i]){
            cnt++;
        }
        else{
            if(tmp=='W'){
                if(cnt==ans1){
                    v1.push_back(i-1);
                }
            }
            else{
                if(cnt==ans1){
                    v2.push_back(i-1);
                }
            }
            tmp=str[i];
            cnt=1;
        }
    }
    if(tmp=='W'){
        if(cnt==ans1){
            v1.push_back(len-1);
        }
    }
    else{
        if(cnt==ans1){
            v2.push_back(len-1);
        }
    }
    for(int i=0;i<len;i++){
        if(str[i]=='W'){
            q1.push(q1.front());
            q1.pop();
            t[1][q2.front()]=0;
            q3.push(q2.front());
            q2.pop();
            q2.push(q3.front());
            q3.pop();
        }
        else{
            q2.push(q2.front());
            q2.pop();
            t[0][q1.front()]=0;
            q3.push(q1.front());
            q1.pop();
            q1.push(q3.front());
            q3.pop();
        }
        addtime(q1,0);
        addtime(q2,1);
        if(!v1.empty()&&v1[0]==i){
            show(q1,0);
            v1.erase(v1.begin());
        }
        if(!v2.empty()&&v2[0]==i){
            show(q2,1);
            v2.erase(v2.begin());
        }
    }
    return 0;
}
