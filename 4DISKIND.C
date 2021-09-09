#include<stdio.h>
#include<malloc.h>


int P, N;
int n[20];
int PD[20], ST[20][2];
int name, i , k, f=0, size=0,start=0, seg=0;
char PDname[20];
int headval=0, lastval = 0;

struct node
{
	int empty;
	int blockno;
	int index;
	struct node *file[10];
	struct node *next;
} *block[20], *temp, *cur, *head,*last,*PDf[10], *PDl[10];

struct node * init(int P)
{
	for(i=0; i<P; i++)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		block[i] = temp;
		block[i]->next = NULL;
		block[i]->empty = 1;
		block[i]->blockno = i;
		block[i]->index = 0;
		for(k=0; k<10; k++)
		{
			block[i]->file[i] = NULL;
		}
	}
	printf("\n");

	block[2]->index = 1;
	block[8]->index = 1;
	block[11]->index = 1;

    /*	for(i=0; i<P; i++)
	{
		printf("\nblock %d =  %d       %d ", i, block[i]->index, block[i]->empty);
	}  */

	head = block[0];
	i=0;

	while(i<P)
	{
		if(block[i]->empty==-1&&block[i]->index!=1)
		{
			head = block[i+1];
			headval++;
		}
		else if(block[i]->index==1)
			i++;
		else
			break;
	}
   //	printf("\nheadval = %d", headval);

	cur = head;
	for(i=headval+1; i<P; i++)
	{
		temp = block[i];
	       if(temp->empty==1&&temp->index!=1)
	       {
			cur->next = block[i];
			block[i]->next = NULL;
			cur = block[i];
	       }
	}

	cur = head;
	while(cur->next!=NULL)
	{
		cur = cur->next;
	}
	last = cur;
	lastval = last->blockno;
    //	 printf("\nlastval = %d", lastval);
	 return head;
}

void printPD()
{
	int e;
	for(e=0; e<f; e++)
	{
		printf("\n%c\t%d", PDname[e], PD[e]);
	}
	return;
}


void printInd()
{
	int e, l=0;
	for(e=0; e<P; e++)
	{

		if(block[e]->index ==1 && block[e]->empty == -1)
		{
			printf("\nBlock no %d\n", e);
			i=0;
			cur = PDf[l];
			while(cur!=NULL)
			{
				block[e]->file[i] = cur;
				printf("\t %d", cur->blockno);
				i++;
				cur = cur->next;
			}
			l++;
		}
	}

}



void updateindex(int size)
{
	for(i=0; i<P; i++)
	{
		if(block[i]->index==1 && block[i]->empty==1)
		{
			temp = PDf[f];
			for(k=0; k<size; k++)
			{
				block[i]->file[k] = temp;
				temp = temp->next;
			}
			printf("Index block = %d", i);
			PD[f] = i;
			block[i]->empty = -1;
			break;
		}
	}
}

struct node * updateblocks(int size)
{
	int e=0, r;
	temp = head;
	PDf[f] = head;
	PDf[f] = temp;
	while(e<size)
	{
		cur = head;
		cur->empty = -1;
		head = head->next;
		temp = cur;
		e++;
	}
	temp->next = NULL;
	headval = head->blockno;
    //	printf(" HEadvalue = %d", headval);

	PDl[f] = temp;
	printf("\nFile is containedc in blocks");
	cur = PDf[f];
	while(cur!=NULL)
	{
		printf("\t%d", cur->blockno);
		cur = cur->next;
	}

	if(block[15]->empty==-1)
	{
		lastval = -1;
		headval = -1;
	}
	updateindex(size);
	return head;
}


void addtoblock()
{
	int m=0, freesize = 0;
	printf("Enter no of programs");
	scanf("%d",&N);
	while(m<N)
	{
		freesize = 0;
		printf("\nHEadval = %d", headval);
		printf("\nlastval = %d", lastval);

		printf("Enter Name of the program(as a number)");
		scanf("%d", &name);
		printf("Enter Size of the program");
		scanf("%d", &size);
		for(temp = head; temp!=NULL; temp=temp->next)
		{
			if(temp->empty == 1)
				freesize++;
		}
		if(size<=freesize)
		{
			PDname[f] =(char)name+65;
			PDf[f] = head;
			head = updateblocks(size);
			f++;
		}
		else
		{
			printf("NOT EENOUGH SPACE");
		}
		m++;
	}
	printPD();
	return;
}

struct node * deleteblock()
{
	int d, ind;
	printPD();
	printf("Enter which program you want to delete");
	scanf("%d", &d);
	ind = PD[d-1];
	for(i=d-1; i<f-1; i++)
	{
		PD[i] = PD[i+1];
		PDname[i] = PDname[i+1];
	}
	f--;

	temp = PDf[d-1];
	while(temp!=NULL)
	{
	       temp->empty = 1;
	       temp = temp->next;
	}

	block[ind]->index = 0;
	for(i=0; i<size; i++)
	{
		block[ind]->file[i] = NULL;
	}

	PDl[d-1]->next = head;
	head = PDf[d-1];
	headval = head->blockno;
	printPD();
	printInd();
	return head;
}


void main()
{
	int n, ch;
	clrscr();
	printf("Enter no of Physical Blocks");
	scanf("%d", &P);
	head = init(P);
	while(1)
	{
		printf("\n1.Insert 2. Delete 3.Print Physical Directory 4.Print Index block 5. Exit");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: addtoblock();
				break;
			case 2: head =  deleteblock();
				break;
			case 3: printPD();
				break;
			case 4: printInd();
				break;
			case 5: exit(0);

		}
	}
 }
