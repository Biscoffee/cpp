#include<stdio.h>
int cmp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
int main()
{
    int w;
    int n;
    scanf("%d",&w);
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    int left = 0;
    int right = n - 1;
    int cnt = 0;
    while(left <= right){
        if(a[left] + a[right] <= w){
            left++;
            right--;
    } else {
        right --;
    }
    cnt ++;
    }
    printf("%d\n",cnt);
    return 0;
}