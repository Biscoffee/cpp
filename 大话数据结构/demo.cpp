void CreateListTail(LinkList *L,int n)
{
    LinkList p,r;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    r = *L;
    for(i=0;i<n;i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
}