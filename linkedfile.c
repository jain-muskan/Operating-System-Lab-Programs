//Linked file
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct reclinks
{
    int index;
    struct reclinks* next;
};
typedef struct reclinks node;
struct lfile
{
    int id,size,sindex,eindex;
    struct reclinks *start,*end;
}files[20];
bool blocks[100];
void init()
{
    //initialising files' id to -1 to show files not allocated yet
    for(int i=0;i<20;i++)
        files[i].id=-1;
    //iniialissing the memory of sec9ondary storage (blocks) to false
    for(int i=0;i<100;i++)
        blocks[i]=false;
}
node* create(int data)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->index=data;
    temp->next=NULL;
    return temp;
}

int count=100;
void printblock(int id)
{
    if(files[id].id>=0)
    {
        node* temp=files[id].start;
        while(temp!=NULL)
           {
               printf("%d--> ",temp->index);
               temp=temp->next;
           }
        printf("\n-------\n");
    }
}
void insert(int id,int size)
{
    if(files[id].id<0)
        {
        files[id].id=id;
        files[id].size=size;
            if(count >=size)
            {
                int r;
                node* temp=(node*)malloc(sizeof(node));
                node* temp1;
                for(int i=0;i<size;i++)
                {
                while(1)
                {
                    r=rand()%100;
                    if(blocks[r]==false)
                    {
                        count--;
                        blocks[r]=true;
                        break;
                    }

                }

                temp1=create(r);
                if(i==0){
                        temp=create(r);
                    files[id].start=temp;
                    files[id].sindex=temp->index;
                }
                else
                   {
                temp->next=temp1;
                temp=temp1;
                   }
                }
                files[id].end=temp;
                files[id].eindex=temp->index;

            }
        }
        else
            printf("Already allocated data");

}

void del(int id)
{
    if(files[id].id>=0)
    {
        node* temp=files[id].start;
        while(temp!=NULL)
        {
            blocks[temp->index]=false;
            temp=temp->next;
        }
        files[id].id=-1;
    }
}
void print()
{
    printf("File || Start || End\n");
    for(int i=0;i<20;i++)
    {
        if(files[i].id>=0)
         {
        printf("%d  %d  %d\n",files[i].id,files[i].sindex,files[i].eindex);
        printf("--------\n");
         }
    }
    printf("\n");
}
int main()
{
    int x,id,size;
    init();
    while(1)
    {
        printf("1)Insert 2)Delete 3)Print 4)Print(blocks of file) ... any other key to exit : ");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            printf("Index of file and size(no of blocks): ");
            scanf("%d %d",&id,&size);
            insert(id,size);
            break;
        case 2:
            printf("Id of the file to be deleted : ");
            scanf("%d",&id);
            del(id);
            break;
        case 3:
            print();
            break;
        case 4:
            printf("Id of block:");
            scanf("%d",&id);
            printblock(id);
            break;
        default:
            printf("Thank you  ");
            exit(1);
        }
    }
}
