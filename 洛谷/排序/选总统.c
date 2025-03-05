#include<stdio.h>
#include<string.h>
int cmp(const char *a,const char *b)
{
    if(strlen(a) > strlen(b)){
        return 1;
    }
    if(strlen(a) < strlen(b)){
        return -1;
    }
    return strcmp(a,b);
}
int main()
{
    int n;
    int max_vote = 0;
    char votes[20][101];
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%s",votes[i]);
    }
    for(int i = 0;i < n;i++){
        if(cmp(votes[i],votes[max_vote]) > 0){
            max_vote = i;
        }
    }
    printf("%d\n",max_vote + 1);
    printf("%s\n",votes[max_vote]);
}