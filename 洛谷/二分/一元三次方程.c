#include<stdio.h>
double f(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    double a,b,c,d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    for(double i = -100;i <= 100;i++){
        double l = i,r = i+1;
        if(a*l*l*l+b*l*l+c*l+d == 0){
            printf("%.2lf ",l);
        }
        if(f(l) * f(r) < 0){
            while(r - l > 1e-8){
                double mid = (l+r)/2;
                if(f(l) * f(mid) <= 0){
                    r = mid;
                }else{
                    l = mid;
                }
            }
            printf("%.2lf ",l);
        }
    }
    return 0;
}