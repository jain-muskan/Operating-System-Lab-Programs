#include<stdio.h>
#include<conio.h>
#define MAX 20

int c=0;
struct node
{
	int n;
	struct node *link;
}*cur,*temp,*f[MAX];
struct frame
{
	int name;
	struct node * start,*end;
}t[MAX];

int no,bs,tm,rm;

void insert_file()
{
	int fn,fs,rb,i,y,j;
	printf("\nFile Name:");
	scanf("%d",&fn);
	printf("\nFile Size:");
	scanf("%d",&fs);
	rb=fs/bs;
	if(rb*bs<fs)
	rb=rb+1;
	printf("\n%d Blocks are required",rb);
    //	printf("\nfs=%d",fs);
	if(fs<=rm)
	{
		i=0;
		rm=rm-rb*bs;
		while(f[i]->n!=-1)
		i++;
		t[c].name=fn;
		cur=(struct node*)malloc(sizeof(struct node));
		cur->n=i;
		cur->link=NULL;
		f[i]=cur;
		t[c].start=f[i];
		cur=f[i];
		rb--;
		j=i+1;
		do
		{
			if(f[j]->n==-1)
				{

				temp=(struct node*)malloc(sizeof(struct node));
				temp->n=j;
				temp->link=NULL;
				f[j]=temp;
				cur->link=f[j];
				cur=cur->link;
				rb--;
				if(rb==0)
				t[c].end=cur;

			}
			j++;

		}while(rb>0 && j<no);
		temp=t[c].start;
	       /*	while(temp->n!=-1)
		{
			printf("\t%d",temp->n);
			temp=temp->link;
		}   */
		c++;
	}
	else
	printf("\nNOT ENOUGH MEMORY");
}

int search_file(int fn)
{
	int i;
	for(i=0;i<c;i++)
	{
		if((t[i].name)==fn)
	      //	return (t[i].start)->n;
	      return i;
	}
	return -1;
}

void del_file()
{
	int fn,x=-1,i,j,c;
	printf("\nFile Name:");
	scanf("%d",&fn);
   /*	for(i=0;i<c;i++)
	{
		if(t[i].name==fn)
		{
			x=i;
			break;
		}
	}*/
	x=search_file(fn);
	if(x==-1)
	{
		printf("\nFile not present");
	}
	else
	{
		t[x].name=-1;
		cur=(struct node*)malloc(sizeof(struct node));
		cur=t[x].start;
		while(cur->link!=NULL)
		{
			f[cur->n]->n=-1;
			f[cur->n]->link=NULL;
			rm+=bs;
			cur=cur->link;
		}
		rm+=bs;
		f[cur->n]->n=-1;
		f[cur->n]->link=NULL;
		t[x].start=NULL;
		free(cur);
		cur=(struct node*)malloc(sizeof(struct node));
		f[cur->n]->n=-1;
		t[x].end=NULL;
		free(cur);
	}
}

void print_table()
{
	int i;
	printf("\nDIRECTORY\n");
	printf("NAME	START	END\n");
	for(i=0;i<c;i++)
	{
		printf("%d	%d	%d\n",t[i].name,t[i].start->n,t[i].end->n);
	}
}

void main()
{
	int ch,i,p,fn;
	clrscr();
	printf("\nGive Total Memory And Number of blocks");
	scanf("%d %d",&tm,&no);
	for(i=0;i<no;i++)
	f[i]->n=-1;
	rm=tm;
	bs=tm/no;
	printf("\nEach Size:%d",bs);
	do
	{
		printf("\nSelect One:\n1.Insert A File\n2.Delete A File\n3.Print File Table\n4.Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert_file();
				break;
			case 2:	del_file();
				break;
			case 3: printf("\nName:");scanf("%d",&fn);
				p=search_file(fn);
				printf("%d",t[p].start->n);
				break;
			case 4: print_table();
				break;
			case 5: exit();

		}
	}while(ch<=5 && ch>0);
	getch();
}


