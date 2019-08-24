#include<bits/stdc++.h>
using namespace std;
char ch[100005];
int ans[100005];
int ans1[100005];
char a[100005];
char b[100005];
int n;
int add(int s1,int g){
    for(int i=1; i<=s1; i++)
        a[i] = ch[i] - '0';
    for(int i=1; i<=n-s1; i++)
        b[i] = ch[i+s1] - '0';

    reverse(a+1,a+s1+1);
    reverse(b+1,b+n-s1+1);
    int len_ans = max(s1,n-s1);
    int jw = 0;
    if(g==1){
        for(int i=1; i<=len_ans; i++){
            ans[i] = (a[i]+b[i]+jw)%10;
            jw = (a[i]+b[i]+jw)/10;
        }
        if(jw!=0){
            ans[++len_ans] = jw;
        }
        reverse(ans+1,ans+len_ans+1);
    }
    else{
         for(int i=1; i<=len_ans; i++){
            ans1[i] = (a[i]+b[i]+jw)%10;
            jw = (a[i]+b[i]+jw)/10;
        }
        if(jw!=0){
            ans1[++len_ans] = jw;
        }
        reverse(ans1+1,ans1+len_ans+1);
    }
    for(int i=1;i<=len_ans;i++){
        a[i] = '\0';
        b[i] = '\0';
    }
    return len_ans;
}
bool judge(int t1, int t2){
    if(t1<t2){
        return true;
    }
    if(t1>t2){
        return false;
    }
    for(int i=1,j=1;i<=t1,j<=t2;i++,j++){
        if(ans[i]==ans1[j]) continue;
        if(ans[i]>ans1[j]){
            return false;
        }
        else{
            return true;
        }
    }
    return true;
}
int main (){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>ch[i];
    }
    if(n%2==0){
        int cnt = n/2;
        for(int i=cnt+1;i<=n;i++){
            if(ch[i]=='0'){
                cnt++;
            }
            else{
                break;
            }
        }
        int len_ans = add(cnt,1);
        int t1 = len_ans;
        cnt =n/2;
        for(int i=cnt+1;i>0;i--){
            if(ch[i]=='0'){
                cnt--;
            }
            else{
                break;
            }
        }
         len_ans = add(cnt,2);
         int t2 = len_ans;
        if(judge(t1,t2)){
            for(int i=1; i<=t1; i++){
                cout<<ans[i];
            }
        }
        else{
            for(int i=1; i<=t2;i++){
                cout<<ans1[i];
            }
        }
    }
    else{
        int cnt0 = n/2;
        int cnt1 = n/2+1;
        bool falg = false;
        for(int i=cnt1;i<=n;i++){
            if(ch[i]==ch[i-cnt1+1]) continue;
            if(ch[i]>ch[i-cnt1+1]){
                falg = true;//cnt0
                break;
            }
            else{
                falg =false;
                break;
            }
        }
        if(!falg){
            for(int i=cnt0+1;i<=n;i++){
                if(ch[i]=='0'){
                    cnt0++;
                }
                else{
                    break;
                }
            }
            int len_ans = add(cnt0,1);
            int t1= len_ans;
              cnt0 =n/2;
            for(int i=cnt0+1;i>0;i--){
                if(ch[i]=='0'){
                    cnt0--;
                }
                else{
                    break;
                }
            }
             len_ans = add(cnt0,2);
             int t2= len_ans;
            if(judge(t1,t2)){
            for(int i=1; i<=t1; i++){
                cout<<ans[i];
            }
        }
        else{
            for(int i=1; i<=t2;i++){
                cout<<ans1[i];
            }
        }
        }
        else{
            for(int i=cnt1+1;i<=n;i++){
                if(ch[i]=='0'){
                    cnt1++;
                }
                else{
                    break;
                }
            }
            int len_ans = add(cnt1,1);
            int t1= len_ans;
           /* for(int i=1; i<=len_ans; i++){
                cout<<ans[i];
            }
            cout<<endl;*/
            cnt1 =n/2+1;
            for(int i=cnt1+1;i>0;i--){
                if(ch[i]=='0'){
                    cnt1--;
                }
                else{
                    break;
                }
            }
             len_ans = add(cnt1,2);
             int t2= len_ans;
            if(judge(t1,t2)){
                for(int i=1; i<=t1; i++){
                    cout<<ans[i];
                }
            }
            else{
                for(int i=1; i<=t2;i++){
                    cout<<ans1[i];
                }
            }

        }
    }
}
