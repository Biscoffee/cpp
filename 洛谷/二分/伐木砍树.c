#include<stdio.h>

int a[1000000];
int n,m;
int check(int x){
    long long total = 0;
    for(int i = 0;i < n;i++){
        if(a[i] > x){
            total += a[i] - x;
        }
    }
    return total >= m;
}
int main()
{
    scanf("%d %d",&n,&m);
    int max_height = 0;
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
        if(a[i] > max_height){
            max_height = a[i];
        }
    }
    int l = 0,r = max_height;
    int result = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
           result = mid;
           l = mid + 1; 
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n",result);
    return 0;
}