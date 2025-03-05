/*
vector  变长数组，倍增的思想
  size() 返回元素个数
  empty() 返回是否为空
  clear() 清空
  front()/back() //返回第一个元素和最后一个元素
  push_back()/pop_back() .//插入和删除
  begin()/end()  //迭代器
  []
 支持比较运算，按字典序

int main()
{
    
    vector<int> a;
    for (int i = 0; i < 10; i++)
        a.push_back(i);  //插入
//三种遍历方法
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    for(vector<int>::iterator i = a.begin();i!=a.end();i++)  cout << *i << " ";
        cout << endl;
    for(auto x : a) cout << x << " ";  
        cout << endl;
    return 0;
}

########################################################

pair<int,int>
  first,第一个元素
  支持比较运算，以first为第一关键字，以second为第二关键字（字典序）
int main()
{
    pair<int,string> p;
    pair<int,pair<int,int>>
}

#################################################

string  字符串 substr() 返回子串
  size()/length() 返回字符串长度
  empty()
  clear()
  substr(起始下标，(子串长度)) 返回子串    cout<<s.substr(0,3)<<endl;
  c_str() 返回字符串所在字符数组的起始地址




####################################################

queue,队列· 
push() //队尾插入一个元素
pop()  //弹出队头元素
front()//返回队头元素 
back()//返回队尾元素

没有clear函数，清空：q = queue<int>();

#####################################################

priority_queue,优先队列，默认是大根堆

定义：priority_<int> heap;
定义小根堆：priority_queue<int,vector<int>,greater<int>> heap;

  push() 插入一个元素
  top() 返回堆顶元素
  pop() 弹出堆顶元素
  定义小根堆的方式：priority_queue<int,vector<int>,greater<int>> heap;
  定义大根堆的方式：priority_queue<int> heap;
  自定义排序方式：



##################################################

stack 栈 
push() //向栈顶插入元素
pop()  // 返回栈顶元素
top()  // 弹出栈顶元素

#####################################################

deque,双端队列
  size()
  empty()
  clear()
  front()/back()
  push_back() //向队尾插入一个元素
  /pop_back()  //弹出队尾元素
  push_front()/pop_front()  //向队头插入一个元素/弹出队头元素
  []



#######################################################

set,map,multiset,multimap 基于平衡二叉树（红黑树）实现，动态维护有序序列
size()
empty()
clear()
begin()/end()  ++, --  返回前驱和后继 （前面一个数/后面一个数）
  set<int>S;
  multiset<int>S;

  set/multiset
    insert() 插入一个数
    find() 查找一个数
    count() 返回某一个数的个数
    erase()
      (1)输入是一个数x，删除所有x O(k+logn)
      (2)输入一个迭代器，删除这个迭代器
    lower_bound()/upper_bound()
      lower_bound(x) 返回大于等于x的最小的数的迭代器
      upper_bound(x) 返回大于x的最小的数的迭代器
  map/multimap
    insert() 插入的数是一个pair
    erase() 输入的参数是pair或者迭代器
    find()
    []  注意multimap不支持此操作。 时间复杂度是 O(logn)
    lower_bound()/upper_bound()
    int main()
    {
        map<string,int> a;
        a["a"] = 1;
        cout << a["a"] << endl; //像数组一样使用
    }


#########################################################

unordered_set,unordered_map,unordered_multiset,unordered_multimap 基于哈希表来实现
  和上面类似，增删改查的时间复杂度是 O(1)
  不支持 lower_bound()/upper_bound()，迭代器的++，--


############################

bitset  压位
  bitset<10000> s;
  ~, &, |, ^
  >>, <<
  ==, !=
  []
  count() 返回有多少个1
  any()  判断是否至少有一个1
  none()  判断是否全为0
  set() 把所有位置成1
  set(k,v)  将第k位变成v
  reset() 把所有位变成0
  flip()  等价于~
  flip(k) 把第k位取反
  

*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
using namespace std;

