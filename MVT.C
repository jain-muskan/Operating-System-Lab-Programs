#include<stdio.h>
#include<conio.h>
#define MAX 20
int jb[MAX],a[MAX];
void main()
{
	int tm,rm,jb[MAX],i,j,k,jk;
	printf("\nTotal Memory:");
	scanf("%d",&tm);
	printf("\nJobs:");
	rm=tm;

	k=0;i=0;
	do
	{
		scanf("%d",&jk);
		if(jk<=rm)
		{
			a[k]=jk;
			rm=rm-jk;
			k++;
		}
		jb[i]=jk;
		i++;
	}while(jk!=-1);


	printf("\nJobs  Allomem ");
	for(i=0;i<k-1;i++)
	{
		printf("\n%d    %d",i+1,a[i]);

	}
	printf("\nExternal Fragmentation:%d",rm-1);
	getch();

}
