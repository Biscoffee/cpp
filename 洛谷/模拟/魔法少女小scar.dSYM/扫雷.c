#include <stdio.h>

#define MAXN 100  
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char **grid = (char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
        grid[i] = (char*)malloc(sizeof(char)*m);
        scanf("%s",grid[i]);
    }
    char **result = (char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++){
        result[i] = (char*)malloc(sizeof(char)*m);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='*'){
                result[i][j] = '*';
            }else{
                int count = 0;
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        if(x==0 && y==0) continue;
                        if(i+x>=0 && i+x<n && j+y>=0 && j+y<m && grid[i+x][j+y]=='*'){
                            count++;
                        }
                    }
                }
                result[i][j] = count+'0';
            }
        }
    }
        







}