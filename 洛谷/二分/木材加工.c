#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int k,n;
int a[100010];

int check(int l)
{
    int total = 0;
    for(int i=0;i<n;i++)
    {
        total += (a[i] / l);
    }
    return total >= k;
    
}
int main()
{
    scanf("%d %d",&n,&k);
    int max_len = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i] > max_len)
            max_len = a[i];
    }
    int l = 1,r = max_len;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid+1;
            ans = mid;
        }
        else
            r = mid-1;
    }
    printf("%d\n",ans);
    return 0;
    
}