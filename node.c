#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    struct Node *link;
};

struct Node * creatnode (int value)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    n->value = value;
    n->link = NULL;
    return n;
}

void incert (struct Node *head,struct Node * p)
{
    while(head != NULL)
    {
        if(head->link == NULL)
        {
            head->link = p;
            break;
        }
        head = head->link;
    }
}
void printlist (struct Node * p)
{
    int j = 1;
    while(p != NULL)
    {
        printf("node %d = %d\n",j,p->value);
        j++;
        p = p->link;
    }
}
int max(struct Node *head)
{
    int max = 0;
    while(head != NULL)
    {
        
        if(head->value > max)
        {
            max = head->value;
        }
        head = head->link;
    }
    //printf("max = %d\n",max);
    return max;
}
int digitcount (int num)
{
    int count = 0;
    while(num > 0)
    {
        num = num / 10;
        count++;
    }
    return count;
}


int main()
{
    struct Node *p,*q ,*head, *current;
    p = (struct Node *)malloc(sizeof(struct Node));
    q = (struct Node *)malloc(sizeof(struct Node));
    head = (struct Node *)malloc(sizeof(struct Node));

    int n,i = 0,num;
    printf("Enter the number of nodes:");
    scanf("%d",&num);
    printf("Enter the nodes:\n");
    for(i = 0; i < num; i++)
    {
        scanf("%d",&n);
        if(i == 0)
        {
            head = creatnode(n);
        }
        else
        {
            p = creatnode(n);
            incert(head,p);
        }
    }
    //printlist(head);
    int high = max(head);
    int m,arr[100],j = 0;
    scanf("%d",&m);
    while(head != NULL)
    {
        if(digitcount(head->value) == m && head->value % 3 == 0) 
        {
            printf("%d ",head->value);
            arr[j] =
        }
        head=head->link;
    }
    return 0;
}


