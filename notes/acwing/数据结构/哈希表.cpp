#include<iostream>
 #include<cstring>

using namespace std;
const int N = 200003;

int h[N];//存储哈希表
int e[N];//存储数据   
int ne[N];//存储下一个位置
int idx;//指针

void insert(int x)
{
    int k = (x % N + N) % N; //取模
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for(int i = h[k];i != -1;i = ne[i])
    {
        if(e[i] == x)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op,&x);
        if(op[0] == 'I')  insert(x);
        else{
            if(find(x)) puts("Yes");
            else puts("No");
        }
    }
}