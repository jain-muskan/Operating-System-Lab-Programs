#include<stdio.h>
#include<conio.h>
#define MAX 20

int at[MAX],ct[MAX],bt[MAX],bt1[MAX],tat[MAX],wt[MAX],rq[MAX],tq[MAX];
int i,n,T,t,t1,tt,k=-1,ttm,rqr=-1,rqf=-1,tqf=-1,tqr=-1;
float tatg,wtg;

void add_queue(int q[],int *f ,int *r,int x)
{
	int front,rear;
	front=*f;
	rear=*r;
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		q[rear]=x;
	}
	else if(rear==MAX-1 && front!=0)
	{
		rear=0;
		q[rear]=x;
	}
	else
	{
		rear++;
		q[rear]=x;
	}
	*f=front;
	*r=rear;
}
int del_queue(int q[],int *f,int *r)
{
	int front,rear,val;
	front=*f;
	rear=*r;

	if(front==-1 && rear==-1)
	{
		return -1;
	}
	val = q[front];
	if(front==rear)
	front=rear=-1;
	else
	{
		if(front==MAX-1)
		front=0;
		else
		front++;
	}
	*f=front;
	*r=rear;
	return val;
}

void ready_queue()
{
	int i,m=0,dv,tp;
	ttm=0;
	t1=0;
	while(T<tt)
	{
		if(m<n)
		{
		if(T!=0)
		t1=T-ttm+1;
		while(t1<=T)
		{

			for(i=0;i<n;i++)
			{
				if(at[i]==t1)
				{
					add_queue(rq,&rqf,&rqr,i);
					m++;
				}
			}
			t1++;
		}
		}

		do
		{
			dv=del_queue(tq,&tqf,&tqr);
			if(dv>-1)
			add_queue(rq,&rqf,&rqr,dv);
		}
		while(dv!=-1);
		ttm=0;

		do
		{
			tp=del_queue(rq,&rqf,&rqr);
			if(tp>-1)
			{

			if(bt1[tp]<=t && bt1[tp]!=0)
			{

				T+=bt1[tp];
				ttm+=bt1[tp];
				ct[tp]=T;
				bt1[tp]=0;

			}
			else
			{
				T+=t;
				ttm+=t;
				bt1[tp]=bt1[tp]-t;
				if(m<n)
				add_queue(tq,&tqf,&tqr,tp);
				else
				add_queue(rq,&rqf,&rqr,tp);
			}
			}
		}
		while(tp!=-1);
	}
}



void table_cal()
{


	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
}


void table_print()
{
	clrscr();
	printf("   	       ROUND ROBIN\n\n");
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
		bt1[i]=bt[i];
		tt+=bt[i];

	}
	printf("\nTime slice:");
	scanf("%d",&t);
	ready_queue();
	table_cal();
	table_print();
	getch();
}

