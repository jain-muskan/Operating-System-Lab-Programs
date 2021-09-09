#include<stdio.h>
#include<conio.h>
#define MAX 20

int at[MAX],ct[MAX],bt[MAX],tat[MAX],wt[MAX],rq[MAX],tq[MAX];
int i,n;
float tatg,wtg;

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void ready_queue()
{
	int i,j;
	for(j=n-2;j>=0;j--)
	{
		for(i=0;i<=j;i++)
		{
			if(tq[i]>tq[i+1])
			{
				swap(&tq[i],&tq[i+1]);
				swap(&rq[i],&rq[i+1]);
			}
			if(tq[i]==tq[i+1])
			{
				if(bt[rq[i]]>bt[rq[i+1]])
				{
					swap(&tq[i],&tq[i+1]);
					swap(&rq[i],&rq[i+1]);
				}
			}
		}
	}
}


void table_cal()
{
	nt wt2=0,wt1=0;
	if(at[rq[0]]!=0)
	wt1=at[rq[0]];
	ct[rq[0]]=bt[rq[0]]+wt1;
	for(i=1;i<n;i++)
	{
		wt2=0;
		if(at[rq[i]]>ct[rq[i-1]])
		wt2=at[rq[i]]-ct[rq[i-1]];

		ct[rq[i]]=ct[rq[i-1]]+bt[rq[i]]+wt2;
	}

	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		tatg+=tat[i];
		wtg+=wt[i];
	}
}


void table_print()
{
	clrscr();
	printf("   		 SHORTEST JOB FIRST\n\n");
	printf("Jobs	AT	BT	CT	TAT	WT\n");
	for(i=0;i<n;i++)
	{
		printf("%d	%d	%d	%d	%d	%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	for(i=0;i<n;i++)
	{
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
	printf("\nGive Arrival times and Burst times:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&at[i],&bt[i]);
		tq[i]=at[i];
		rq[i]=i;
	}

	ready_queue();
	table_cal();
	table_print();
	getch();
}

