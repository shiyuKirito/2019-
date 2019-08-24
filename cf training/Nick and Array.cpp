#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int change(int x){
    return (x*-1)-1;
}
int ans[maxn];
int min_num = 0x3f3f3f3f;
int max_num = -1*10000000;
int tn = 0;
//>0 j o
//<  j o
int max_i = -1;
int min_i = -1;
int main (){
     int n;
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>max_num&&a[i]>=0){
            max_i = i;
        }
        if(a[i]<min_num&&a[i]<0){
            min_i = i;
        }
        max_num = max(a[i],max_num);
        min_num = min(a[i],min_num);
        if(a[i]>=0){
            tn++;
        }
     }
     bool falg = true;
     if(tn==0){
        if(n%2==0){
            for(int i=1;i<=n;i++){
                printf("%d ",a[i]);
            }
            printf("\n");
            return 0;
        }
        else{
            for(int i=1; i<=n; i++){
                if(falg==true&&a[i]==min_num){
                    printf("%d ",change(a[i]));
                    falg = false;
                }
                else{
                    printf("%d ",a[i]);
                }
            }
            printf("\n");
            return 0;
        }
     }
     falg = true;
     if(tn%2==0&&(n-tn)%2==0){
         for(int i=1;i<=n;i++){
            if(a[i]>=0){
                printf("%d ",change(a[i]));
            }
            else{
                printf("%d ",a[i]);
            }
         }
         printf("\n");
         return 0;
     }
     falg = true;
     if(tn%2==0&&(n-tn)%2==1){
			for(int i=1; i<=n; i++)
			{
				if(a[i]>=0&&i!= max_i)
				{
					a[i] = change(a[i]);
				}
			}
			if(change(a[min_i])>a[max_i]||a[max_i]==0)
			{
			    a[min_i]=change(a[min_i]);
			    a[max_i]=change(a[max_i]);
			}
     }
     falg = true;
    if(tn%2==1&&(n-tn)%2==0){
            for(int i=1; i<=n; i++)
			{
				if(a[i]>=0&&i!=max_i)
				{
					a[i]=change(a[i]);
				}
			}
			if((n-tn)>0&& ((change(a[min_i]))>a[max_i]||a[max_i]==0))
			{
			    a[min_i]=change(a[min_i]);
			    a[max_i]=change(a[max_i]);
			}
     }
    if(tn%2==1&&(n-tn)%2==1){
         for(int i=1;i<=n;i++){
            if(a[i]>=0){
                printf("%d ",change(a[i]));
            }
            else{
                printf("%d ",a[i]);
            }
         }
         printf("\n");
         return 0;
     }
     for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
     }
     printf("\n");
 
}
