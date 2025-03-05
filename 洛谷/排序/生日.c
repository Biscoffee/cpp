#include<stdio.h>
struct birthday
{
    char s[21];
    int year;
    int month;
    int day;
    int num;
} a[101];
int cmp(const void *a,const void *b){
    struct birthday *c = (struct birthday *)a;
    struct birthday *d = (struct birthday *)b;
    if(c->year != d->year){
        return c->year - d->year;
    }
    else if(c->month != d->month){
        return c->month - d->month;
    }
    else if(c->day != d->day){
        return c->day - d->day;
    }else{
        return d -> num - c -> num;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%s %d %d %d",a[i].s,&a[i].year,&a[i].month,&a[i].day);
        a[i].num = i;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int i = 0;i < n;i++){
        printf("%s\n",a[i].s);
    }
    return 0;
}