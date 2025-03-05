#include<stdio.h>
#include<stdlib.h>
struct apple{
    int h;
    int w;
} a[5010];
int cmp(const void *a,const void *b){
    return ((struct apple *)a)->w - ((struct apple *)b)->w;
}
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int a1,b1;
    scanf("%d %d",&a1,&b1);
    for(int i = 0;i < n;i++){
        scanf("%d %d", &a[i].h, &a[i].w);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int cnt = 0;
    for(int i = 0;i < n;i++){
        if(a[i].h <= (a1+b1) && a[i].w <= s){
            cnt ++;
            s -= a[i].w;
        }
    }
    printf("%d",cnt);
    return 0;
}