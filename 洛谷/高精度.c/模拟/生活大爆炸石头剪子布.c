#include<stdio.h>
#include<string.h>
int main()
{
    int n,n1,n2;
    int w1 = 0;
    int w2 = 0;
    int win[5][5] = {
        {0,-1,1,1,-1},
        {1,0,-1,1,-1},
        {-1,1,0,-1,1},
        {-1,-1,1,0,1},
        {1,1,-1,-1,0}
    };
    scanf("%d %d %d",&n,&n1,&n2);
    int a1[n1];
    int a2[n2];
    for(int i = 0;i < n1;i++){
        scanf("%d",&a1[i]);
    }
    for(int i = 0;i < n2;i++){
        scanf("%d",&a2[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int a = a1[i % n1];
        int b = a2[i % n2];
       if(win[a][b] ==1){
              w1++;
         }
         else if(win[a][b] == -1){
            w2++;
         }

    }
    
    printf("%d %d\n",w1,w2);
    return 0;
}