#include<stdio.h>
struct student
{
    int id;
    int score;
} a[5010];

int main()
{
    int n;
    double m;
    scanf("%d %lf",&n,&m);
    for(int i = 0;i < n;i++){
        scanf("%d %d",&a[i].id,&a[i].score);
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n - i - 1;j++){
            if(a[j].score < a[j + 1].score){
                struct student temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            } else if(a[j].score == a[j + 1].score){
                if(a[j].id > a[j + 1].id){
                    struct student temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }
    int rank = m * 1.5;
    if(rank > n){
        rank = n;
    }
    int interviwew_score = a[rank - 1].score;
    int cnt = 0;
    for(int i = 0;i < n;i++){
        if(a[i].score >= a[rank - 1].score){
            cnt++;
        }else{
            break;
        }
    }
    printf("%d %d\n",interviwew_score,cnt);  
    for(int i = 0;i < cnt;i++){
        printf("%d %d\n",a[i].id,a[i].score);
    } 
}