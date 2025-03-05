#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int*)b - *(int*)a;
}
int main()
{
  int N,B;
  scanf("%d %d",&N,&B);
    int a[N];
    for(int i = 0;i < N;i++){
        scanf("%d",&a[i]);
    }  
    int cnt = 0;
    int ttl = 0;
    qsort(a,N,sizeof(int),cmp);
    for(int i = 0;i < N;i++){
        ttl  += a[i];
        cnt++;
        if(ttl >= B){
            break;
        }
    }
    printf("%d\n",cnt);
    return 0;

}