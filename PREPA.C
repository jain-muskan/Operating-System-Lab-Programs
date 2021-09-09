#include<stdio.h>
#include<conio.h>
#define MAX 20

int at[MAX],ct[MAX],p[MAX],bt1[MAX],bt[MAX];
float tat[MAX],wt[MAX];
int i,n,clock=0,TM=0,j;

void ready_queue()
{
	int x;
	while(clock<TM)
	{
		x=find_low(clock);
		bt1[x]=bt1[x]-1;
		if(bt1[x]==0)
		{
			ct[x]=clock+1;
			tat[x]=ct[x]-at[x];
			wt[x]=tat[x]-bt[x];
		}
		clock++;
	}
}

int find_low(int c)
{
	int index=0;
	while((at[index]>c || bt1[index]==0) && index<n)
	index+=1;
	for(j=index+1;j<n;j++)
	{
		if(at[j]<=c && bt1[j]!=0)
		{
			if(p[j]<p[index])
			index=j;
			if(p[j]==p[index])
			{
				if(at[j]<at[index])
				index=j;
			}
		}
	}
	if(index<n)
	return index;
	else
	return -1;

}


void table_print()
{
	float tatg=0,wtg=0;
	clrscr();
	printf("   		    PRE-EMPTIVE PRIORITY\n\n");
	printf("Jobs	AT	BT	PR	CT	TAT	WT\n");
	for(i=0;i<n;i++)
	{
		printf("%d	%d	%d	%d	%d	%.f	%.f\n",i+1,at[i],bt[i],p[i],ct[i],tat[i],wt[i]);
	}
	for(i=0;i<n;i++)
	{
//		printf("%f %f\n",tat[i],wt[i]);
		tatg+=tat[i];
		wtg+=wt[i];
	}
	tatg=tatg/n;
	wtg=wtg/n;
	printf("\nTAT avg=%f\nWT avg=%f",tatg,wtg);
}


void main()
{

	clrscr();
	printf("Number of processes: ");
	scanf("%d",&n);
	printf("\nGive Arrival times ,Burst times and PRIORITY:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&at[i],&bt[i],&p[i]);
		TM+=bt[i];
		bt1[i]=bt[i];
	}

	ready_queue();
	table_print();
	getch();
}

