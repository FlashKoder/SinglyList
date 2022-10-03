#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *start)
{
int num,n;
struct node *new_node , *ptr;
printf("Enter number of elements: ");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
printf("Enter data: ");
scanf("%d",&num);
new_node = (struct node*)malloc(sizeof(struct node));
new_node->data=num;
if(start==NULL)
{
new_node->next=NULL;
start=new_node;
}
ptr=start;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=new_node;
new_node->next=NULL;
}
return start;
}
void display(struct node *ptr)
{
if(ptr==NULL)
{
printf("Linked list is empty.\n");
}
while(ptr!=NULL)
{
printf("%d\n",ptr->data);
ptr=ptr->next;
}
}
void search(struct node *ptr,int val)
{
int i=1;
if(ptr==NULL)
{
printf("Linked list empty.\n");
}
else
{
while(ptr!=NULL)
{
if(ptr->data==val)
{
printf("%d is %dth node\n",val,i);
break;
}
i++;
ptr=ptr->next;
}
if(ptr==NULL)
{
printf("Value is not in the linked list.\n");
}
}
}
struct node *Begin(struct node *ptr,int val)
{
struct node *head;
head =(struct node*)malloc(sizeof(struct node));
head->data = val;
head->next = ptr;
return head;
}
struct node *End(struct node *ptr,int val)
{
struct node *str,*head;
str = (struct node*)malloc(sizeof(struct node));
str->data = val;
head = ptr;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next = str;
str->next = NULL;
return head;
}
struct node *Before(struct node *ptr, int val,int index)
{
struct node *head,*str;
str = (struct node*)malloc(sizeof(struct node));
str->data=val;
int i=0;
head = ptr;
while(i!=index-1)
{
ptr=ptr->next;
i++;
}
str->next=ptr->next;
ptr->next=str;
return head;
}
struct node *After(struct node*ptr,  int val, int index)
{
struct node *head,*str;
str = (struct node*)malloc(sizeof(struct node));
str->data = val;
head = ptr;
int i=0;
while(i!=index)
{
ptr=ptr->next;
i++;
}
str->next = ptr->next;
ptr->next = str;
return head;
}
struct node *insert(struct node *ptr,int val)
{
struct node *head;
printf("*******MENU*******\n");
printf("1.Insert node begining of the list.\n");
printf("2.Insert node at the end of the list.\n");
printf("3.Insert node before the given  node.\n");
printf("4.Insert node after the given node\n");
int ch,index;
printf("->Enter your choice: ");
scanf("%d",&ch);
switch (ch)
{
case 1:
      head = Begin(ptr,val);
      break;
case 2:
      head = End(ptr,val);
      break;
case 3:
      printf("Enter index before you insert: ");
      scanf("%d",&index);
      head = Before(ptr,val,index);
      break;
case 4:
      printf("Enter index after you insert: ");
      scanf("%d",&index);
      head = After(ptr,val,index);
      break;

default:
      printf("\nInvalid choice.");
      break;
}
return head;
}
struct node *D_begin(struct node *ptr)
{
if(ptr==NULL)
{
printf("List is empty.\n");
}
else
{
struct node *start;
start=ptr;
ptr=ptr->next;
free(start);
}
return ptr;
}
struct node *D_end(struct node *ptr)
{
if(ptr==NULL)
{
printf("List is empty.\n");
}
else
{
struct node *start,*preptr;
start=ptr;
while(start->next!=NULL)
{
preptr=start;
start=start->next;
}
preptr->next=NULL;
}
return ptr;
}
struct node *D_val(struct node *ptr,int val)
{
struct node *str,*preptr;
str=ptr;
while(str->data!=val)
{
preptr=str;
str=str->next;
}
if(str==NULL)
{
printf("Value is not present in the list.\n");
}
else
{
struct node *temp;
temp=str;
preptr->next=str->next;
free(temp);
}
return ptr;
}
struct node *delete(struct node *ptr)
{
struct node *head;
printf("******MENU*****\n");
printf("1.Delete a node from begin.\n");
printf("2.Delete a node from end.\n");
printf("3.Delete a node between from data.\n");
int ch,val;
printf("->>Enter your choice: ");
scanf("%d",&ch);
switch (ch)
{
case 1:
      head = D_begin(ptr);
      break;
case 2:
     head = D_end(ptr);
     break;
case 3:
     printf("Enter your value to delete: ");
     scanf("%d",&val);
     head = D_val(ptr,val);
     break;
default:
      printf("Invalid input.\n");
      break;
}
}
int main()
{
int ch,val;
printf("*******MENU*******\n");
printf("1. for create linked list.\n");
printf("2. for display linked list.\n");
printf("3. for searching an element.\n");
printf("4. for insertion.\n");
printf("5. for deletion.\n");
printf("6. for exit program.\n");
while(1)
{
printf("Enter your choice: ");
scanf("%d",&ch);
switch (ch)
{
case 1:
      start=create(start);
break;
case 2:
      display(start);
break;
case 3:
      printf("Enter value to search: ");
      scanf("%d",&val);
      search(start,val);
break;
case 4:
      printf("Enter value to insert: ");
      scanf("%d",&val);
      start = insert(start,val);
break;
case 5:
      start=delete(start);
break;
case 6:
      return 0;
break;
default:
      printf("Invalid input.\n");
    break;
}
}
return 0;
}