#include <stdio.h>
int cmp(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    int total = 0;
    while(n > 1){
        int cost = a[0] + a[1];
        total += cost;
        a[0] = cost;
        n--;
        qsort(a,n,sizeof(int),cmp);
    }
    printf("%d\n",total);
    return 0;
}