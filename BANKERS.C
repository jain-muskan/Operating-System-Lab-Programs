#include<stdio.h>
#include<conio.h>
#define m 3
#define n 5

int avail[m],max[n][m],alloc[n][m],need[n][m],req[m],work[m],finish[n],rpn,ss[n],c=0;
int safety_module(void);

void main()
{
	int i,j,flag=0,sm;
	clrscr();
	printf("Give Availability for %d Resources",m);
	for(i=0;i<m;i++)
	scanf("%d",&avail[i]);
	printf("\nMaximum number of resources for each processes:");
	for(i=0;i<n;i++)
	{
		printf("\nFor P%d:",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("\nAllocated resource number for each processes:");
	for(i=0;i<n;i++)
	{
		printf("\nFor P%d:",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	printf("\nRequest:");
	for(i=0;i<m;i++)
	scanf("%d",&req[i]);
	printf("\nFor Process No.:");
	scanf("%d",&rpn);
	for(i=0;i<m;i++)
	{
		if(req[i]>need[rpn][i])
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		for(i=0;i<m;i++)
		{
			if(req[i]>avail[i])
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			for(i=0;i<m;i++)
			{
				avail[i]=avail[i]-req[i];
				alloc[rpn][i]+=req[i];
				need[rpn][i]-=req[i];
			}
			sm=safety_module();
			if(sm==1)
			{
				printf("\nSAFE\nSAFE SEQUENCE:");
				for(i=0;i<n;i++)
				printf("%d\t",ss[i]);
			}
			else
			printf("\nUNSAFE");
		}
		else
		printf("\nProcess is waiting");

	}
	else
	printf("\nERROR");
	getch();
}

int safety_module()
{
	int i,j,x=0;
	for(i=0;i<m;i++)
	work[i]=avail[i];
	for(i=0;i<n;i++)
	finish[i]=0;
	while(x!=-1)
	{
		x=find();
		finish[x]=1;
		ss[c]=x;
		c++;
		for(i=0;i<m;i++)
		work[i]+=alloc[x][i];
	}
	for(i=0;i<n;i++)
	{
		if(finish[i]==0)
		return 0;
	}
	return 1;
}

int find()
{
	int i,j,f;
	for(i=0;i<n;i++)
	{
		if(finish[i]==0)
		{
			f=1;
			for(j=0;j<m;j++)
			{
				if(need[i][j]>work[j])
				f=0 ;
			}
			if(f==1)
			return i;
		}
	}
	return -1;
}