#include<stdio.h>
#include<stdlib.h>
void Merge_sort(int a[],int left,int right)
{
    if(left >= right)
        return;
    int mid = (left + right) / 2;
    Merge_sort(a,left,mid);
    Merge_sort(a,mid+1,right);
    int i = left;
    int j = mid + 1;
    int k = 0;
    int *temp = (int *)malloc(sizeof(int)*(right - left + 1));
    while(i <= mid && j <= right)
    {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i <= mid)
        temp[k++] = a[i++];
    while(j <= right)
        temp[k++] = a[j++];
    for(int i = 0;i < k;i++)
    {
        a[left + i] = temp[i];
    }
    free(temp);
}
void quick_sort(int a[],int left,int right)
{
    if(left >= right)
        return;
    int i = left;
    int j = right;
    int key = a[left];
    while(i < j)
    {
        while(i < j && a[j] >= key)
            j--;
        a[i] = a[j];
        while(i < j && a[i] <= key)
            i++;
        a[j] = a[i];
    }
    a[i] = key;
    quick_sort(a,left,i-1);
    quick_sort(a,i+1,right);
}
int main()
{

    int n;
    long long int m;
    int a[2000010];
    //int *a;
    //a = (int *)malloc(sizeof(int)*m);
    scanf("%d %lld",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d",&a[i]);
    }
    quick_sort(a,0,m-1);
    for(int i = 0;i < m;i++){
        printf("%d ",a[i]);
    }

    //free(a);
    return 0;
}