#include<stdio.h>
#include<conio.h>
#define MAX 20

int c=0;
struct node
{
	int n;
	int indb;
	int lf[10];
	struct node *link;
}*cur,*temp,*f[MAX],*next;
struct frame
{
	int name;
	int start;
}t[MAX];

int no,bs,tm,rm;

void init()
{
	int i,j;
	for(i=0;i<no;i++)
	{
		f[i]->n=-1;
		f[i]->indb=0;
		for(j=0;j<10;j++)
		f[i]->lf[j]=-1;
		f[i]->link=NULL;

	}

}

void insert_file()
{
	int fn,fs,rb,i,y,j,k,p;
	printf("\nFile Name:");
	scanf("%d",&fn);
	printf("\nFile Size:");
	scanf("%d",&fs);
	rb=fs/bs;
	if(rb*bs<fs)
	rb=rb+1;
	printf("\n%d Blocks are required and 1 indexed",rb);
    //	printf("\nfs=%d",fs);
	if(fs<=rm)
	{
		i=0;
		rm=rm-(rb+1)*bs;
		while(f[i]->n!=-1 || f[i]->indb==1)
		i++;
		t[c].name=fn;
		t[c].start=i;
		cur=(struct node*)malloc(sizeof(struct node));
		cur->n=fn;
		cur->indb=1;
		cur->link=NULL;
		f[i]=cur;
		cur=f[i];
		temp=f[i];
		j=i+1;
		while(rb>0 && j<no)
		{
			k=0;
			if(f[j]->n==-1 && f[j]->indb==0)
			{

				next=(struct node*)malloc(sizeof(struct node));
				next->n=fn;
				next->indb=0;
				next->link=NULL;
				f[j]=next;
				temp->lf[k]=j;
				k++;
				cur->link=f[j];
				cur=cur->link;
				rb--;
			}
			j++;


		}
		p=0;
		while(f[i]->lf[p]!=-1)
	       {
		printf("%d",f[i]->lf[p]);
		p++;
	       }
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
	int fn,x=-1,i,j,c,z,p;
	printf("\nFile Name:");
	scanf("%d",&fn);
	x=search_file(fn);
	if(x==-1)
	{
		printf("\nFile not present");
	}
	else
	{
		t[x].name=-1;
	       //	cur=(struct node*)malloc(sizeof(struct node));
		z=t[x].start;
		f[z]->indb=0;
		f[z]->n=-1;
		p=0;
		while(f[z]->lf[p]!=-1)
		{
			f[f[z]->lf[p]]->n=-1;
		    //	f[f[z]->lf[p]]->link=NULL;
			f[z]->lf[p]=-1;
			p++;
		}
		f[z]->link=NULL;
		t[x].start=-1;
		rm+=p*bs;
		printf("\nrm=%d",rm);

	}
}


void print_table()
{
	int i;
	printf("\nDIRECTORY\n");
	printf("NAME	INDEX	\n");
	for(i=0;i<c;i++)
	{
		printf("%d	%d\n",t[i].name,t[i].start);
	}
	printf("\n");
	for(i=0;i<no;i++)
	{
	printf("%d %d %d\n",i,f[i]->n,f[i]->indb);
	}
}

void main()
{
	int ch,i,p,fn;
	clrscr();
	printf("\nGive Total Memory And Number of blocks");
	scanf("%d %d",&tm,&no);
	rm=tm;
	bs=tm/no;
	printf("\nEach Size:%d",bs);
	init();
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
				printf("%d",t[p].start);
				break;
			case 4: print_table();
				break;
			case 5: exit();

		}
	}while(ch<=5 && ch>0);
	getch();
}


