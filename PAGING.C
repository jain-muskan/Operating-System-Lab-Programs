#include<stdio.h>
#include<conio.h>
#define MAX 20
void main()
{
	int f[MAX],nf,ps,s,i,j,np;
	clrscr();
	printf("No.of Frames:");
	scanf("%d",&nf);
	for(i=0;i<nf;i++)
	f[i]=-1;
	printf("\nProcess Size:");
	scanf("%d",&ps);
	printf("\nPage Size");
	scanf("%d",&s);
	np=ps/s;
	if(np*s<ps)
	np+=1;
	printf("\n%d Frames are required",np);
	if(np<=nf)
	{
		for(i=0;i<np;i++)
		{
			f[(i+3)%nf]=i;
		}
		printf("\nAllocation:\nFrame no.\tPage\n");
		for(i=0;i<nf;i++)
		{
			printf("%d\t%d\n",i,f[i]);
		}

	}
	else
	printf("\nAllocation mot possible");
	getch();
}