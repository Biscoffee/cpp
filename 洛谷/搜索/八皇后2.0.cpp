#include <iostream>
using namespace std;

const int N = 20;
int n;
bool col[N],dg[N],udg[N];
bool answer[N];
void dfs(int x,int y,int s)
{
    if(y == n) y = 0,x++;
    if(x == n)
    {
        if(s == n)
        {
            for(int i = 0;i < n;i++) cout << answer[i] << " ";
            cout << endl;
        }
        return;
    }
    dfs(x,y+1,s);
    if(!col[y] && !dg[x+y] && !udg[x-y+n])
    {
        answer[y] = y + 1;
        s++;
        col[y] = dg[x+y] = udg[x-y+n] = true;
        dfs(x,y+1,s+1);
        col[y] = dg[x+y] = udg[x-y+n] = false;

    }
}

int main()
{
    cin >> n;
    dfs(0,0,0);
    return 0;
}