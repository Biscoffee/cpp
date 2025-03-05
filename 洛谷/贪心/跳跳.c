#include<stdio.h>
int cmp(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}
int mian(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    for(int i = 0;i < n;i++){
        result += 
    }
}