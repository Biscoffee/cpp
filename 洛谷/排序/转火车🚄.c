#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    int cnt = 0;
    for(int i = 0;i < n - 1;i++){
        for(int j = 0;j < n - 1- i;j++){
            if(a[j]> a[j+1]){
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                cnt ++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}