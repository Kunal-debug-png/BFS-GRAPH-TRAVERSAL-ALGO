#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define count1 0
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};


int isEmpty(struct queue *q){
    if(q->r==q->f){
	return 1;
    }
    return 0;
}
int isFull(struct queue *q){
    if(q->r==q->size-1){
	return 1;
    }
    return 0;
}


void enqueue(struct queue *q, int val){

	q->r++;
	q->arr[q->r] = val;
	//count1=count1+1;


}
void show(struct queue *q){
     for(int i=q->f+1;i<=q->r;i++)
    {
	printf("%d",q->arr[i]);
    }
}
int isPresent(struct queue *q,int k){
    int count=0;
    for(int i=q->f;i<q->r;i++)
    {

		if(q->arr[i]==k){
			count=1;
		}
    }
    return count;


}
int linearSearch(int arr[],int key,int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			return i;
		}
	}
	return -1;
}

int lengthQueue(struct queue *q)
{
	int n3=0;
	for(int i=q->f+1;i<=q->r;i++)
	{
		n3++;
	}
	return n3;
}

int main(){
	clrscr();
    struct queue q;
    int n;
    printf("\nEnter the Number of elements you want to insert in a graph");
    scanf("%d",&n);
    int v[100];
    for(int i=0;i<n;i++)
	scanf("%d",&v[i]);
    printf("\nAssuring that you want to traverse from %d",v[0]);
    q.size = n;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    int arr[100][100];
    for(i=0;i<n;i++)
    {
	for(int j=0;j<n;j++)
	{
		arr[i][j]=0;
	}
    }
    int n5;
    for(i=0;i<n;i++)
    {
	printf("\n Enter the nmber of adjacent edge of %d",v[i]);
	scanf("%d",&n5);
	for(int j=0;j<n5;j++)
	{
		int n7;
		scanf("%d",&n7);
		int n6=linearSearch(v,n7,n);
		if(n6!=-1){
			arr[i][n6]=1;
		}
	}
    }
    int visited[100];
    for(i=0;i<n;i++)
    {
	visited[i]=0;
    }
	for(i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
		if(visited[i]==0)
		{
			  enqueue(&q,v[i]);
			  visited[i]=1;
		}
		if(arr[i][j]==1)
		{
			if(visited[j]==0)
			{
				enqueue(&q,v[j]);
				visited[j]=1;
			}
		}
	    }
    }
    show(&q);


    getch();
    return 0;
}