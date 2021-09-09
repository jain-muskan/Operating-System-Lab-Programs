#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 20
struct node
{
	char data[10];
	struct node* link;
}*fds[MAX];
int l;
//struct node* insert(struct node*[]);
/*struct node* del(struct node*,char []);
int search(struct node*,char[]);*/
//void print(struct node*[]);

/*struct node* insert(struct node* fds[])
{
 struct node *cur ,*temp,*next;
 int ch,i;
 char dn[10],fn[10];
*/
/*
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
  return head; */




 /* cur=head;
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
  printf("\nList is empty");   */

//}

/*struct node* del(struct node* head ,char ele[])
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
} */
void main()
{
 int ch,x,ch1,ch2,i,j,k;
 char fn[10],dn[10];
 struct node *cur,*next,*temp;
 clrscr();
 do
 {
  printf("\nSelect any option :\n1.To insert\n2.To delete\n3.To print\n4.To Search\n5.Exit");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1:
  {
  printf("\nTo Insert 1.Directory 2.File");
 scanf("%d",&ch1);
 switch(ch1)
 {
	case 1:
	{
		printf("\nDirectory Name:");
		scanf("%s",dn);
		cur=(struct node*)malloc(sizeof(struct node));

		strcpy(cur->data,dn);
		cur->link=NULL;
		fds[l]=cur;
	    //	fds[l]->link=NULL;
		l++;
		break;
	}
	case 2:
	{
		printf("\nFile name:");
		scanf("%s",fn);
		printf("\nIn Directory:");
		scanf("%s",dn);
		i=-1;
		k=0;
		while(k<l)
		{
			if(strcmp(fds[k]->data,dn)==0)
			i=k;
			k++;
		       //	else
		       //	break;
		}
	     //	i++;
		temp=fds[i];
		cur=(struct node*)(malloc(sizeof(struct node)));
		strcpy(cur->data,fn);
		cur->link=NULL;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=cur;

		printf("\n%s inserted in %s",fn,dn);
		printf("%s",(fds[i]->link)->data);
		break;
	}
	}


   printf("\nLength:%d",l);
   break;
  }
  case 2:
  {
   printf("To delete 1.FILE 2.DIRECTORY");
   scanf("%d",&ch2);
   switch(ch2)
   {
   case 1:
   printf("\nName of the file:");
   scanf("%s",&fn);
   printf("\nFrom Directory:");
   scanf("%s",&dn);
   while(k<l)
   {
	if(strcmp(fds[k]->data,dn)==0)
	{
		temp=fds[k]->link;
		while(strcmp(temp->data,fn)!=0)
		{
			cur=temp;
			temp=temp->link;
		}
		next=temp->link;
		cur->link=next;
		free(temp);
		break;
	}
   }

   break;
   case 2:
   printf("\nDirectory :");
   scanf("%s",&dn);
   while(k<l)
   {
	if(strcmp(fds[k]->data,dn)==0)
	{
		j=k;
		break;
	}

   }
   for(k=l-1;k>j;k--)
   {
	fds[k]=fds[k-1];
   }
   l--;
   break;
  }
  break;
 }
  case 3:
 {
  struct node *cur;
  int i;
  for(i=0;i<l;i++)
  {
       //	cur=(struct node*)malloc(sizeof(struct node));
	cur=fds[i];
	printf("\n%s:",cur->data);
	while(cur!=NULL)
	{
		cur=cur->link;
		printf("%s\t",cur->data);
	}
      //	printf("%s",cur->data);
  }
 // print(fds);
  break;
 }
  case 4:
  printf("\nDirectory name:");
 // gets(ele);
// scanf("%s",ele);
 // x=search(head,ele);
  if(x!=-1)
  printf("\nDir is at position %d",x);
  else
  printf("\nDir not found");
  break;
  case 5:
  exit (0);
  break;
 }
 }while(ch<=5);
 getch();
}