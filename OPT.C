#include<stdio.h>
#include<conio.h>
#define MAX 25

int p[MAX],rq[MAX],n,f,ch,c=-1,pf=0,dr=0,rear=-1;


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


int find_count(int z)
{
	int j,k,temp,index,start,h[MAX];
	for(k=0;k<f;k++)
	{
	h[k]=-1;
	}
	for(j=n-1;j>=z;j--)
	{
		for(k=0;k<f;k++)
		{
			if(rq[k]==p[j])
			{
				h[k]=j;
			}
		}
	}

	if(rear<f-1)
	start=rear+1;
	if(rear==f-1)
	start=0;
	index=start;
	temp=h[start];
	for(k=start;k<f;k++)
	{

			if(h[index]<h[k])
			{
			       index=k;
			       temp=h[k];
			}
			if(h[k]==-1)
			return k;


	}

	for(k=0;k<start;k++)
	{

			if(h[index]<h[k])
			{
			       index=k;
			       temp=h[k];
			}
			if(h[k]==-1)
			return k;


	}
	printf("\t%d",index);

	return index;

}


void main()
{
	int i,j,c1,flag=0;
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

		if(c==-1)
		{
			if(rear==f-1 || flag==1)
			{
				flag=1;
				c1=find_count(i+1);
				if(c1!=-1)
				rq[c1]=p[i];
				else
				push(p[i]);

			}
			else
			push(p[i]);
			pf++;
		}
		print_queue();
		if(pf>f)
		dr=pf-f;

	}
	printf("\nPage Fault Rate=%d\nPage Replacement Rate%d",pf,dr);
	getch();
}

