#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main(){
    cin>>s1>>s2;
    int len1=s1.size();
    int len2=s2.size();
    for(int i=0;i<len1;i++){
        if(s1[i]<s2[i]){
            s1[i]=s1[i]-(s2[i]-'A')+26;
        }
        else{
            s1[i]=s1[i]-(s2[i]-'A');
        }
        s2=s2+s1[i];
    }
    cout<<s1<<endl;
    return 0;
}
