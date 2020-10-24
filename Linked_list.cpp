#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
}*first,*last;

node create(int arr[],int n)
{
    int i;
    node *t,*last;
    first = new node();
    first->data = arr[0];
    first->next=NULL;
    last = first;
    for(int i=1;i<n;i++)
    {
        t = new node;
        t->data = arr[i];
        t->next=NULL;
        last->next=t;
        last = t;
    }
}

void display(node *p)
{
    while (p->next!=NULL)
    {
        cout<<p->data<<"   ->  ";
        p = p->next;
    }
    cout<<p->data;
}

node *sortInsert(node *p,int key)
{
    node *q;
    node *t=new node();
    p = first;
    if (first==NULL)
    {
        t->data = key;
        t ->next=NULL;
        first = t;
    }
    else
    {
        while (p&&p->data<key)
        {
            q=p;p=p->next;
        }
        t->data=key;
        t->next=q->next;
        q->next=t;
    }
    return p;
    
}

int main()
{
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
    node *s;
    int a[4]={1,2,7,10};
    create(a,4);
    sortInsert(first,2);
    display(first);
}