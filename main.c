#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
  int prn,marks;
  char name[20];
  struct node *prev,*next;

};

struct node* create(struct node * head)
{ 
int stud;
char naw[20];
struct node *temp,*q;
q=head;

  printf("ENTER PRN NO :");
  scanf("%d",&head->prn);
  printf("ENTER NAME :");
  scanf("%s",naw);
  strcpy(head->name,naw);
  printf("ENTER IE MARKS :");
  scanf("%d",&head->marks);
head->prev=NULL;
head->next=NULL;
printf("HOW MANY STUDENTS YOU WANT TO ADD?");
scanf("%d",&stud);
printf("ENTER THE INFORMATION:\n");
for(int i=0;i<stud;i++)
{
  temp=(struct node *)malloc(sizeof(struct node));
  printf("ENTER PRN NO :");
  scanf("%d",&temp->prn);
  printf("ENTER NAME :");
  scanf("%s",temp->name);
  printf("ENTER IE MARKS :");
  scanf("%d",&temp->marks);

  temp->next=NULL;
  temp->prev=head;
  head->next=temp;
  head=head->next;
}
return q;
  }

void display(struct node *head)
{ struct node *p;
p=head;
   while(p!=NULL)
  {
    printf("PRN NO:%d\n",p->prn);
    printf("NAME:%s\n",p->name);
    printf("IE MARKS:%d\n\n\n",p->marks);
    p=p->next;
  }

}
void delete_middle(struct node *head)
{ int po;
printf("ENETR PRN NO\n");
scanf("%d",&po);



struct node *p,*q;
p=head;
q=head->next;






while(p->prn!=po)
{
  p=p->next;
  q=q->next;
}
p->prev->next=p->next;
q->prev=p->prev;
free(p);


}
void delete_first(struct node *head)
{
  struct node *p=head;
  head=head->next;
  //head->next->prev=NULL;
  head->prev=NULL;
  free(p);
}
void delete_last(struct node *head)
{
  struct node *p=head;
  while(p!=NULL&&p->next!=NULL)
  {
    p=p->next;

  }
  p->prev->next=NULL;
  free(p);

}

int main(void) {
  int a;
  struct node *head;
  head=(struct node *)malloc(sizeof(struct node));

 
do
{
  printf("1)CREATE\n2)DELETE FIRST PRN NO\n3)DELETE MIDDLE PRN NO\n4)DELETE LAST PRN NO\n5)DISPLAY\n6)EXIT\n");
  printf("\nENTER YOUR CHOICE:");
  scanf("%d",&a);
  switch(a)
  {
    case 1:
    head=create(head);
    break;

    case 2:
    delete_first(head);
    break;
    
    case 3:
    delete_middle(head);
    break;
    
    case 4:
    delete_last(head);
    break;
    
    case 5:
    display(head);
    break;
   

  }

}while(a!=6);

}