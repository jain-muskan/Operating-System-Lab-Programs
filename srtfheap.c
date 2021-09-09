#include<stdio.h>
#include<conio.h>
typedef struct
{
	int arrival;
	int burst;
	int tat;
	int waiting;
	int num;
}process;
int last=0,set1=0;
process heap[10],pro[10];
void insert(process elem)
{
 int te,i;
 process temp;
 if(set1==0)
 {
  heap[1]=elem;
  last=1;
  set1=1;
 }
 else
 {
  heap[++last]=elem;
  te=last;
  while(te!=1)
  {
   if(heap[te/2].burst>heap[te].burst)
   {
    temp=heap[te];
    heap[te]=heap[te/2];
    heap[te/2]=temp;
   }
   else
    break;
   te=te/2;
  }
 }
 printf("values in heap\n");
 for(i=1;i<=last;i++)
 {
	printf("%d\t",heap[i].num);
 }
 printf("\n");
}
void del()
{
 int i,k;
 process temp;
 i=1;
 heap[i]=heap[last];
 last--;
 if(last==0)
	set1=1;
	while(1)
	{
		if((heap[2*i].burst<heap[i].burst&&2*i<last&&heap[2*i+1].burst>heap[2*i].burst)||(heap[2*i].burst<heap[i].burst&&2*i==last))
        {
            temp=heap[i];
            heap[i]=heap[2*i];
            heap[2*i]=temp;
            i=2*i;
        }
        else if(heap[2*i+1].burst<heap[i].burst&&2*i+1<=last&&heap[2*i].burst>heap[2*i+1].burst)
        {
            temp=heap[i];
            heap[i]=heap[2*i+1];
            heap[2*i+1]=temp;
            i=2*i+1;
        }
        else
            break;
	}
	printf("after deletion :\n");
	for(i=1;i<=last;i++)
		printf("%d\t",heap[i].num);
}

void main()
{
	int n,i,m,t,set=0,j,out[10],avetat=0,avewait=0;
	process temp,prolst[10];
	printf("enter the no of processes\n");
	scanf("%d",&n);
	printf("enter the arrival and burst times\n");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&pro[i].arrival,&pro[i].burst);
		prolst[i].arrival=pro[i].arrival;
		prolst[i].burst=pro[i].burst;
		pro[i].num=i;
	}
	t=m=0;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n-1;i++)
		{
			if(pro[i].arrival>pro[i+1].arrival)
			{
				temp=pro[i];
				pro[i]=pro[i+1];
				pro[i+1]=temp;
			}
			else if(pro[i].arrival==pro[i+1].arrival)
			{
				if(pro[i].burst>pro[i+1].burst)
				{
					temp=pro[i];
					pro[i]=pro[i+1];
					pro[i+1]=temp;
				}
			}
		}
	}
	while(!set)
	{
		while(m<n&&pro[m].arrival==t)
		{
			printf("inserting pro[m] %d\n at t %d",m,t);
			insert(pro[m]);
			m++;
		}
		t++;
		printf("time is %d\n",t);
		if(last==0)
        {
            set=1;
            printf("value is set\n");
        }
		else
		{
			printf("heap[1]->num and burst %d %d\n",heap[1].num,heap[1].burst);
			heap[1].burst--;
			if(heap[1].burst==0)
			{
				printf("burstt o \n");
				out[heap[1].num]=t;
				del();
			}
		}
	}
	for(i=0;i<n;i++)
    {
            pro[i].tat=out[i]-prolst[i].arrival;
            pro[i].waiting=pro[i].tat-prolst[i].burst;
            printf("%d %d\n",pro[i].tat,pro[i].waiting);
    }
    for(i=0;i<n;i++)
    {
        avetat+=pro[i].tat;
        avewait+=pro[i].waiting;
    }
    printf("The tat average is %f :\n The waiting avg is %f :\n ",(float)avetat/n,(float)avewait/n);
	getch();
}
