#include<stdio.h>
#include<string.h>
#define FILE -1
#define NULL 0
typedef struct node
{
 char drn[10];
 struct node *link,*subdir;
}node;

int geti(node *first,char ele[],int po)
{
 int i=1;
 while(strcmp(first->drn,ele)!=0&&first!=NULL)
 {
  first=first->link;
  i++;
 }
 if(first==NULL)
 return -1;
 if(po==0)
 return i;
 if(po==1)
 return first;
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
  temp->subdir=FILE;
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
 pos=geti(first,dn,0);
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

node* insdelud(node* first,int iod)
{
	node *pd=(node*)malloc(sizeof(node));
	char pdn[10];
	printf("Parent directory\n");
	scanf("%s",&pdn);
	pd=geti(first,pdn,1);
	if(iod==0)
	pd->subdir=insert(pd->subdir,1);
	if(iod==1)
	pd->subdir=del(pd->subdir);
	return first;
}

void print(node *first)
{
 while(first!=NULL)
 {
	printf("\n%s",first->drn);
	if(first->subdir!=FILE)
	{
		node *second=first->subdir;
		printf(":");
		while(second!=NULL)
		{
			printf("\t%s",second->drn);
			second=second->link;
		}
	  }
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
	char pdn[10];
	node* first=NULL;
	node* second=NULL;
	clrscr();
	while(1)
	{
		printf("\n1.New master directory 2.Delete master directory\n3.Print 4.Exit\n5.New user directory 6.Delete user directory\n");
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
			printf("Directories");
			print(first);
			break;
			case 4:
			exit(0);
			case 5:
			first=insdelud(first,0);
			break;
			case 6:
			first=insdelud(first,1);
			break;
		}
	}
}