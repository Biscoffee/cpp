#include <iostream>
using namespace std;

#define MaxSize 5
typedef int DataType;

typedef struct Queue
{
    DataType queue[MaxSize];
    int front;
    int rear;
} SeqQueue