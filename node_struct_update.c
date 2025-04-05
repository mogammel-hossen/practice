#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *prev, *next;
};

struct node * creatnode (int value)
{
    struct node *n;
    n = (struct node *)malloc (sizeof(struct node));
    n->value = value;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

void linking (struct node * head, struct node *p)
{
    while(head != NULL)
    {
        if(head->value == p->value)
        {
            p->next = head->next;
            head->next = p;
            p->prev = head;
            break;
        }
        else if (head->next == NULL && head->value != p->value)
        {
            head->next = p;
            p->prev = head;
            break;
        }
        else
        {
            head = head->next;
        }

    }
}


void printlist (struct node * p)
{
    int j = 1;
    while(p != NULL)
    {
        printf("node %d = %d\n",j,p->value);
        j++;
        p = p->next;
    }
}

void deletationofnode (struct node *head, int value)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    while(head != NULL)
    {
        if(head->value == value)
        {
            temp = head;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            free(temp);
        }
        else
        {
            head = head->next;
        }
    }
}

int main()
{
    struct node *p,*head;
    p = (struct node *)malloc (sizeof(struct node));
    head = (struct node *)malloc (sizeof(struct node));
    int num,i,x;
    printf("Number of nodes:");
    scanf("%d",&num);
    for(i = 0; i < num; i++)
    {

        if(i == 0)
        {
            scanf("%d",&x);
            head = creatnode(x);
        }
        else
        {
            scanf("%d",&x);
            p = creatnode(x);
            linking(head,p);
        }
        printlist(head);
    }
    printf("\n");
    int z;
    printf("Enter the number to delete:");
    scanf("%d",&z);
    deletationofnode(head,z);

    printlist(head);
    return 0;
}
