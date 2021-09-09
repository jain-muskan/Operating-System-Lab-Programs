#include<stdio.h>
#include<conio.h>
#define m 3
#define n 5

int avail[m],alloc[n][m],req[n][m],work[m],finish[n],ss[n],c=0;

void main()
{
	int i,j,x,sm,ddlk=0,c,ac;
	clrscr();
	printf("Give Availability for %d Resources",m);
	for(i=0;i<m;i++)
	scanf("%d",&avail[i]);
	for(i=0;i<n;i++)
	finish[i]=0;
	printf("\nAllocated resource number for each processes:");
	for(i=0;i<n;i++)
	{
		ac=0;
		printf("\nFor P%d:",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
			if(alloc[i][j]==0)
			ac++;
		}
		if(ac==m)
		finish[i]=1;
	}
	printf("\nRequest:");
	for(i=0;i<n;i++)
	{
		printf("\nFor P%d:",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&req[i][j]);
		}
	}
	for(i=0;i<m;i++)
	work[i]=avail[i];

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
		ddlk=1;
	}
	if(ddlk!=1)
	printf("\nNO DEADLOCK DETECTED CURRENTLY");
	else
	printf("\nDEADLOCK FOUND");
	getch();
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
				if(req[i][j]>work[j])
				f=0 ;
			}
			if(f==1)
			return i;
		}
	}
	return -1;
}