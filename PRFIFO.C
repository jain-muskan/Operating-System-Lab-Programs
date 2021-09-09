#include<stdio.h>
#include<conio.h>
#define MAX 25

int p[MAX],rq[MAX],f,c=-1,pf=0,dr=0,rear=-1;


void print_queue()
{
	int i;
	printf("\n");
	for(i=0;i<f;i++)
	{
		if(rq[i]!=-1)
		printf("%d\t",rq[i]);
	}
}

void push(int a)
{
	if(rear==-1)
	{
		rear++;
		rq[0]=a;
	}
	else if(rear==f-1)
	{
		rear=0;
		rq[rear]=a;

	}
	else
	{
		rear++;
		rq[rear]=a;
	}
}




void main()
{
	int i,j,n;
	clrscr();
	printf("Enter No. of Frames;");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	rq[i]=-1;
	printf("Number of pages:");
	scanf("%d",&n);
	printf("\nGive Page Sequence:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}

	for(i=0;i<n;i++)
	{
		c=-1;
		for(j=0;j<f;j++)
		{
			if(rq[j]==p[i])
			{
				c=j;
			}
		}
	       //	c=check_queue(p[i]);
		if(c==-1)
		{
			push(p[i]);
			pf++;
		}
		if(pf>f)
		dr=pf-f;

		print_queue();

	}
	printf("\nPage Fault Rate=%d\nPage Replacement Rate%d",pf,dr);
	getch();
}

