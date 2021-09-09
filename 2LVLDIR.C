#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	char name[10];
	int file;
	struct node *SD[10];
	struct node *next;
}*mdir, *head, *temp, *cur, *cur2, *temp2, *temp3, *ptr;

char name[10], n[10];
int i;

struct node * addmd()
{
	int s, p;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->next  = NULL;
	for(i=0; i<10; i++)
		temp->SD[i] = NULL;
	printf("Enter name of Master Dir");
	fflush(stdin);
	gets(temp->name);
	printf("The name of dir/file =   ");
	puts(temp->name);

	if(mdir == NULL)
	{
		mdir = temp;
	}
	else
	{
		cur= mdir;
		while(cur->next!=NULL)
			cur = cur->next;
		cur->next = temp;
	}
	return mdir;
}

struct node * getind()
{
	fflush(stdin);
	printf("Enter MAster Dir name where you want to insert file");
	gets(n);

	printf(":The dir name is   ");
	puts(n);
	temp2 = mdir;
	while(temp2!=NULL)
       {
		if(strcmp(temp2->name,n) == 0)
			return temp2;
		else
			temp2 = temp2->next;
       }
       printf("no such directory exists");
       return mdir;
}

struct node * addud()
{
	temp = (struct node *)malloc(sizeof(struct node));
	temp->next  = NULL;
	for(i=0; i<10; i++)
	{
		temp->SD[i] = NULL;
	}
	printf("Enter name of directory");
	fflush(stdin);
	gets(temp->name);
	printf("The name of dir =   ");
	puts(temp->name);
	ptr = getind();
	for(i=0; i<10; i++)
	{
		if(ptr->SD[i] == NULL)
		{
			ptr->SD[i] = temp;
			ptr->file = 1;
			break;
		}
	}
	return mdir;
 }


void printfd()
{
	cur = mdir;
	while(cur!=NULL)
	{

		printf("\n%s-- \t", cur->name);
		for(i=0; i<10; i++)
		{
			if(cur->SD[i] != NULL)
				printf("-->%s", cur->SD[i]->name);
		}
		cur = cur->next;
	}
	return;
}

struct node *getindud(char n[])
{
	cur = mdir;
	while(cur!=NULL)
	{
		for(i=0; i<10; i++)
		{
			if(strcmp(cur->SD[i]->name,n)==0)
			{
			      return cur;
			}
	       }
	}
	printf("np such user die exists");
	return mdir;
}


struct node *delt(int t)
{
	struct node * del;
	del = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter Directory name you want to delete");
	fflush(stdin);
	gets(n);
	printf("The dir you want to delete is  ");
	puts(n);
	if(t==0)
	{
		printf("ypu want to delete a master directory");
		if(strcmp(mdir->name,n)==0)
		{
			cur = mdir;
			mdir = mdir->next;
			cur->next = NULL;
			free(cur);
			return mdir;
		}
		else
		{
		       cur = mdir;
		       while(strcmp(cur->next->name,n)!=0  &&  cur->next!=NULL)
			cur = cur->next;
		       if(strcmp(cur->next->name,n)==0)
		       {
				del = cur->next;
				cur->next = del->next;
				 del->next = NULL;
				free(del);
				return mdir;
		      }
		      else
		      printf("no such directory exists");
		}
	 }
	else
	{
		printf("you want to delete a user dir");
		ptr = getindud(n);
		for(i=0; i<10; i++)
		{
			if(strcmp(ptr->SD[i]->name, n) == 0)
				ptr->SD[i] = NULL;
		}
	}
	return mdir;
}


void main()
{
	int ch;
	clrscr();
	while(1)
	{
		printf("\n1.INsert MasterDIr 2.Insert user dir 3.Print 4.Delete usr dir 5.Delete mdirdir 6.Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: mdir = addmd();
				break;

			case 2:
				mdir = addud();
				printf("Successfully inserted");
				break;

			case 3: printfd();
				break;

			case 4: mdir = delt(1);
				break;

			case 5: mdir = delt(0);
				break;
			case 6: exit(0);
		}
	}
}