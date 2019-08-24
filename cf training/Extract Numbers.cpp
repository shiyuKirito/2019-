#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
char str[N];
queue<char>q1[N];//char
queue<char>q2[N];//num
int  num[N];
int main(){
    scanf("%s",str+1);
    int s = strlen(str+1);
    int t1 = 0,t2= 0;
    int t = 1;
    for(int i=1;i<=s;i++){
        if(str[i]==','||str[i]==';'){
            num[t++] = i;
        }
    }
    num[0] = 0;
    num[t] = s+1;
    //cout<<num[t]<<endl;
    for(int i=1;i<=t;i++){
        bool falg = true;
        bool falg1 = true;
        for(int j=num[i-1]+1;j<num[i];j++){
            if(j==num[i-1]+1){
                if(str[j]=='0'){
                    falg = false;
                    if(num[i]-1==num[i-1]+1){
                        falg = true;
                    }
                }
                else if(str[j]>='1'&&str[j]<='9'){
                    falg = true;
                }
                else{
                    falg = false;
                }
            }
            else{
                if((str[j]>='a'&&str[j]<='z')||(str[j]>='A'&&str[j]<='Z')||(str[j]=='.')){
                    falg = false;
                }
            }
        }
        if(num[i]==num[i-1]+1&&falg==true){
            falg = false;
            falg1= false;
        }
        for(int j=num[i-1]+1;j<num[i];j++){
            if(falg==true){
                q1[t1].push(str[j]);
            }
            if(falg==false){
                if(falg1==false){
                    q2[t2].push('#');
                    continue;
                }
                q2[t2].push(str[j]);
            }
        }
        if(falg==true){
            t1++;
        }
        if(falg==false){
            t2++;
        }
    }
    if(t1==0){
        printf("-\n");
    }
    else{
        printf("\"");
        for(int i=0;i<t1;i++){
            while(!q1[i].empty()){
                char tmp = q1[i].front();
                q1[i].pop();
                printf("%c",tmp);
            }
           if(i!=t1-1) printf(",");
        }
        printf("\"");
        printf("\n");
    }
    if(t2==0){
        printf("-\n");
    }
    else{
        printf("\"");
        for(int i=0;i<t2;i++){
            while(!q2[i].empty()){
                char tmp = q2[i].front();
                q2[i].pop();
                if(tmp=='#') continue;
                printf("%c",tmp);
            }
            if(i!=t2-1) printf(",");
        }
        printf("\"");
        printf("\n");
    }
}
//123,s1;s2;s3;s4
//123;s1;s2;123
//s1,s2,s3,s4
//first = 0
//1;2;3;4;5;6;7;8;9;10;11
//1,2,3,4,5,6,7,8,9,10,11
//hava zimu
//hava num

