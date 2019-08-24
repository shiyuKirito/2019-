#include<bits/stdc++.h>
using namespace std;
const int mod =1e9+7;
const int N = 1e5+5;
char str[N];
int change(char ch){
  if(ch>='0'&&ch<='9'){
        return ch-'0';
  }
  if(ch<='Z'&&ch>='A'){
        return ((int)ch-'A'+10);
  }
  if(ch<='z'&&ch>='a'){
        return ((int)ch-'a'+36);
  }
  if(ch=='-'){
        return 62;
  }
  if(ch=='_'){
        return 63;
  }
}
int main (){
    scanf("%s",str+1);
    int s= strlen(str+1);
    long long ans = 1;
    for(int i=1;i<=s;i++){
       int tmp = change(str[i]);
        for(int j=0;j<6;j++){
            if(((tmp>>j)&1)==0){
                ans = (ans*3)%mod;
            }
        }
    }
    printf("%lld\n",ans);
}
//61: 111101
//57: 111001
//111111  111101  111011 111001
//111001  111001  111001 111001
//111110
//111111
//111110
//----------------------------------
//111001  111001  111001 111001
