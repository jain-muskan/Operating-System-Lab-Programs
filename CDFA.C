#include<stdio.h>
#include<conio.h>
#define MAX 20

struct frame
{
	int name;
	int start;
	int size;
}f[MAX];

int b[MAX],rear=-1,n,bs,tm,rm;

void insert_file()
{

	int x,fn,fs,rb,i;
	printf("\nFile Name:");
	scanf("%d",&fn);
	printf("\nFile Size:");
	scanf("%d",&fs);
	rb=fs/bs;
	if(rb*bs<fs)
	rb=rb+1;
	if(fs<=rm)
	{	x=find_space(rb);
		if(x!=-1)
		{
			for(i=x;i<x+rb;i++)
			{
				b[i]=0;
			}
			rm=rm-rb*bs;
			rear++;
			f[rear].name=fn;
			f[rear].size=rb;
			f[rear].start=x;
			printf("\nFILE INSERTED");
		}
		else
		{
			printf("\nContiguous Memory unavailable");
		}
	}
	else
	printf("\nNOT ENOUGH MEMORY");
}


int find_space(int rb)
{
	int c=0,i,j;
	for(i=0;i<n;i++)
	{
		if(b[i]==-1)
		{
			for(j=i;j<i+rb && j<n;j++)
			{
				if(b[j]==-1)
				c++;
			}
			if(c==rb)
			return i;
			else
			c=0;
		}
	}
	return -1;

}

int search_file(int fn)
{
	int i;
	for(i=0;i<=rear;i++)
	{
		if(f[i].name==fn)
		return i;
	}
	return -1;
}

void del_file()
{
	int fn,x,i,j;
	printf("\nFile Name:");
	scanf("%d",&fn);
	x=search_file(fn);
	if(x==-1)
	{
		printf("\nFile not present");
	}
	else
	{
		for(i=f[x].start;i<f[x].start+f[x].size;i++)
		b[i]=-1;
		rm=rm+f[x].size*bs;
		for(j=x;j<rear;j++)
		{
			f[j].name=f[j+1].name;
			f[j].start=f[j+1].start;
			f[j].size=f[j+1].size;
		}
		rear--;
		printf("\nFILE SUCCESSFULLY DELETED");
	}

}

void print_table()
{
	int i;
	printf("\nDIRECTORY\n");
	printf("NAME	START	SIZE\n");
	for(i=0;i<=rear;i++)
	{
		printf("%d	%d	%d\n",f[i].name,f[i].start,f[i].size);
	}
}

void main()
{
	int ch,i;
	clrscr();
	printf("\nGive Total Memory And Number of blocks");
	scanf("%d %d",&tm,&n);
	for(i=0;i<n;i++)
	b[i]=-1;
	rm=tm;
	bs=tm/n;
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
			case 3: print_table();
				break;
			case 4: exit();

		}
	}while(ch<5 && ch>0);
	getch();
}


