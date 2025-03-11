#include<iostream>

using namespace std;

const int N = 100010;

int e[N],ne[N],idx,head;

void init()
{
    head = -1;
    idx = 0; //表示当前用到了哪个节点，用于分配新节点的索引
}

void add_at_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx ++;
}

void add(int k,int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
   ne[k] = idx ++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    cin >> m;
    init();
    while(m --)
    {
        int k,x;
        char op;
        cin >> op;
        if(op == 'H')
        {
            cin >> x;
            add_at_head(x);
        }
        else if(op == 'D')
        {
            cin >> k;
            if(!k) head = ne[head];
            else remove(k-1);
        }
        else
        {
            cin >> k >> x;
            add(k-1,x);
        }
    }
}