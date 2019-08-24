#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int sumx[N];
int sumy[N];
int sumz[N];
char str[N];
bool judge(int _x,int _y, int _z){
 if(abs(_x-_y)>1||abs(_x-_z)>1||abs(_z-_y)>1) return false;
 return true;
}
int main (){
    scanf("%s",str+1);
    int n,a,b;
    scanf("%d",&n);
    int sl = strlen(str+1);
    for(int i=1;i<=sl;i++){
        if(str[i]=='x'){
            sumx[i]=sumx[i-1]+1;
            sumy[i]=sumy[i-1];
            sumz[i]=sumz[i-1];
        }
        if(str[i]=='y'){
            sumx[i]=sumx[i-1];
            sumy[i]=sumy[i-1]+1;
            sumz[i]=sumz[i-1];
        }
        if(str[i]=='z'){
            sumx[i]=sumx[i-1];
            sumy[i]=sumy[i-1];
            sumz[i]=sumz[i-1]+1;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        if((b-a)+1<3){
            printf("YES\n");
            continue;
        }
        int lenx = sumx[b]-sumx[a-1];
        int leny = sumy[b]-sumy[a-1];
        int lenz = sumz[b]-sumz[a-1];
        if(judge(lenx,leny,lenz)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
