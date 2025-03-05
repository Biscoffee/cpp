#include<stdio.h>
int check_digits(int a,int b,int c)
{
    int digits[10] = {0};
    while (a > 0)
    {
        digits[a % 10] = 1;
        a /= 10;
    }
    while(b > 0){
        digits[b % 10] = 1;
        b /= 10;
     }
    while (c > 0)
    {
        digits[c % 10] = 1;
        c /= 10;
    }
    for(int i = 1;i <= 9;i++){
        if(digits[i] == 0){
            return 0;
        }
        
    }
    return 1;
}
int main()
{
    int a,b,c;
    int found = 0;
    scanf("%d %d %d",&a,&b,&c);
    for(int k = 1;k <= 1000;k++)
    {
        int x1 = a*k,x2 = b*k,x3 = c*k;
        if(x1 >= 100&& x1 < 1000 && x2 >=100 && x2 < 1000 && x3 >= 100 && x3 < 1000){
            if(check_digits(x1,x2,x3)){
                printf("%d %d %d\n",x1,x2,x3);
                found = 1;
            } 
        }
    }
    if(!found){
        printf("No!!!\n");
    }
}