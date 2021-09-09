#include<stdio.h>
#include<conio.h>
#define MAX 20
int jb[MAX],a[MAX];
void main()
{
	int tm,os,rm,bs,d[MAX],jb[MAX],i,j,c,n,m,IF=0;
	printf("\nTotal Memory:");
	scanf("%d",&tm);
	printf("\nNo. of segments:");
	scanf("%d",&n);
	bs=tm/n;
	printf("\nEach block size=%d",bs);
	printf("\nNo. of jobs=");
	scanf("%d",&m);
	i=0;
	for(i=0;i<m;i++)
	{
		scanf("%d",&jb[i]);

	}
	j=0;
	i=0;
	while(i<m && j<n)
	{

		if(bs>=jb[i])
		{
			a[j]=jb[i];
			j++;
		}
		i++;
	}

	printf("\nJobs  Memory  Allomem IF");
	for(i=0;i<j;i++)
	{
		printf("\n%d    %d      %d      %d",i+1,bs,a[i],bs-a[i]);
		IF+=(bs-a[i]);

	}
	printf("\nExternal Fragmentation:%d %d",(n-j)*bs),IF;
	getch();

}
