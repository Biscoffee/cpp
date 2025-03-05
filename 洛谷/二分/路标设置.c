#include<stdio.h>
#include<math.h>
#include<string.h>
int l,n,k;
int sign[100010];
int check(int d){
    int need = 0;
    int last = 0;
    for(int i = 0;i < n;i++){
        int gap = sign[i] - last;
        if(gap > d){
            need += (gap - 1) / d;
        }
        last = sign[i];
   }
   int gap = l - last;
   if(gap > d){
       need += (gap - 1) / d;
   }
   return need <= k;
}

int main()
{
    scanf("%d %d %d",&l,&n,&k);
    for(int i = 0;i < n;i++){
        scanf("%d",&sign[i]);
    }
    int left = 1,right = l,ans = l;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if(check(mid)){
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    printf("%d",ans);
    return 0;
}