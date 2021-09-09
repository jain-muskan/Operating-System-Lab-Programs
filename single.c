#include<stdio.h>
#include<string.h>
#define FILE -1
#define NULL 0
typedef struct node
{
 char drn[10];
 struct node *link;
}node;

int geti(node *first,char ele[])
{
 int i=1;
 while(strcmp(first->drn,ele)!=0&&first!=NULL)
 {
  first=first->link;
  i++;
 }
 if(first==NULL)
 return -1;
 return i;

}

node* insert(node *first,int pos)
{
 node *temp,*cursor;
 int i;
 temp=(node*)malloc(sizeof(node));
 cursor=(node*)malloc(sizeof(node));
 cursor->link=first;
 for(i=1;i<pos;i++)
 cursor=cursor->link;
 printf("Directory name: ");
 scanf("%s",&temp->drn);
 i=strcmp(first,temp->drn);
 if(i!=0)
 {
  temp->link=cursor->link;
  cursor->link=temp;
  return temp;
 }
 else
 {
  printf("\nDirectory with same name exists");
  return first;
 }
}

node* del(node *first)
{
 int i,pos;
 char dn[10];
 node *temp=(node*)malloc(sizeof(node));
 node *cursor=(node*)malloc(sizeof(node));
 node *pre=(node*)malloc(sizeof(node));
 cursor->link=first;
 temp->link=first;
 pre->link=first;
 printf("\nDirectory name: ");
 scanf("%s",&dn);
 pos=geti(first,dn);
 if(pos==-1)
 {
	printf("Directory not found");
	return first;
 }
 for(i=1;i<pos;i++)
 pre=pre->link;
 for(i=1;i<=pos+1;i++)
 temp=temp->link;
 for(i=1;i<=pos;i++)
 cursor=cursor->link;
 printf("Directory deleted");
 {
  if(pos==1)
  return cursor->link;
  pre->link=cursor->link;
  cursor->link=NULL;
  return first;
 }
}

void print(node *first)
{
 printf("Directories:\n");
 while(first!=NULL)
 {
  puts(first->drn);
  first=first->link;
 }
}

int length(node *first)
{
 int i=0;
 while(first!=NULL)
 {
  first=first->link;
  i++;
 }
 return i;
}

void main()
{
	int ch;
	node* first=NULL;
	clrscr();
	while(1)
	{
		printf("\n1.New directory 2.Delete directory 3.Print 4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			first=insert(first,1);
			break;
			case 2:
			first=del(first);
			break;
			case 3:
			print(first);
			break;
			case 4:
			exit(0);
		}
	}
}