#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int i,l,pos=0;
char ele[10];

struct node
{
 char dir[10];
 struct node *link;
};

struct node* insert(struct node*,char[]);
struct node* del(struct node*,char []);
int search(struct node*,char[]);
void print(struct node*);

struct node* insert(struct node *head,char ele[])
{
 struct node *cur ,*temp,*next;
 if(l==0 )
 {
  cur=(struct node*)malloc(sizeof(struct node));
 // cur->data=ele;
  strcpy(cur->dir,ele);
  cur->link=head;
  head=cur;
  l++;
 }
 else
 {
  cur=(struct node*)malloc(sizeof(struct node));
  temp=head;
  //cur=temp;
  i=0;
  while(i<l-1)
  {
  // temp=cur;
   temp=temp->link;
   i++;
  }

  // cur->data=ele;
   strcpy(cur->dir,ele);
   cur->link=temp->link;
   temp->link=cur;

   l++;
  }
  return head;
 }


void print(struct node* head)
{
  struct node *cur;
  cur=head;
  i=0;
  if(head!=NULL)
  {
  while(i<l)
  {
    printf("\n%s",cur->dir);
    cur=cur->link;
    i++;
  }
  }
  else
  printf("\nList is empty");

}

struct node* del(struct node* head ,char ele[])
{
 struct node *cur ,*next,*temp;
 int pos=0;
 temp=head;
 while(strcmp(temp->dir,ele)!=0)
 {
	pos++;
	temp=temp->link;
 }
 pos++;
 if(pos>l)
 return head;
 else if(pos==1)
 {
  cur=head;
  head=head->link;
  cur->link=NULL;
  free(cur);
  l--;
  return head;
 }
 else
 {
  temp=head;
  for(i=1;i<pos-1;i++)
  temp=temp->link;
  cur=temp->link;
  temp->link=cur->link;
  free(cur);
  l--;
  return head;
 }

}

int search(struct node* head ,char ele[])
{
 struct node *temp;
 int pos=0;
 temp=head;
 while(strcmp(temp->dir,ele)!=0)
 {
	pos++;
	temp=temp->link;
 }
 pos++;
 if(pos>l)
 return -1;
 else
 return pos;
}
void main()
{
 int ch,x;
 struct node *head=NULL,*cur,*next,*temp;
 clrscr();
 do
 {
  printf("\nSelect any option :\n1.To insert\n2.To delete\n3.To print\n4.To Search\n5.Exit");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1:
  {
   printf("\nElement:");
  // gets(ele);
  scanf("%s",ele);
   head=insert(head ,ele);
   printf("\nLength:%d",l);
   break;
  }
  case 2:
  {
   printf("\nName");
  // gets(ele);
   scanf("%s",ele);
   head=del(head,ele);
   printf("\nLength:%d",l);
   break;
  }

  case 3:
  print(head);
  break;
  case 4:
  printf("\nname:");
 // gets(ele);
 scanf("%s",ele);
  x=search(head,ele);
  if(x!=-1)
  printf("\nFile is at position %d",x);
  else
  printf("\nFile not found");
  break;
  case 5:
  exit (0);
  break;
 }
 }while(ch<=5);
 getch();
}