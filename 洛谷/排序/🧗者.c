#include<stdio.h>
#include<math.h>
struct direct{
    int x;
    int y;
    int z;
} a[50010];
int cmp(const void *a,const void *b){
    struct direct *c = (struct direct *)a;
    struct direct *d = (struct direct *)b;
    return c->z - d->z;
} 
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
    }
    qsort(a,n,sizeof(a[0]),cmp);//按照z坐标排序
    double sum_dis = 0.0;
    for(int i = 0;i < n - 1;i++){
        int dx = a[i+1].x - a[i].x;
        int dy = a[i+1].y - a[i].y;
        int dz = a[i+1].z - a[i].z;
        double dis = sqrt(1.0*dx*dx + 1.0*dy*dy + 1.0*dz*dz);
        sum_dis += dis;
    }
    printf("%.3lf\n",sum_dis);
}