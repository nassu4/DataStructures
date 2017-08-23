#include<stdio.h>
#include<stdlib.h>

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty( Queue Q );
int IsFull( Queue Q );
Queue CreateQueue( int MaxElements );
void MakeEmpty( Queue Q );
void Enqueue( int x, Queue Q );
void Dequeue( Queue Q );
int  FrontAndDequeue( Queue Q );
int	Front( Queue Q );

#define MinQueueSize 5

struct QueueRecord
{
	int Capacity;
	int Front;
	int Rear;
	int Size;
	int *Array;
};

/*判断队列是否为空*/ 
int IsEmpty( Queue Q )
{
	return Q->Size == 0;
}

/*使队列为空*/ 
void MakeEmpty( Queue Q )
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

/*控制队头队尾的下标*/ 
static int Succ( int value, Queue Q)
{
	if( ++value == Q->Capacity )
		value = 0;
	return value;
}

/*判断是否是满队列*/ 
int IsFull( Queue Q )
{
	return Q->Size == Q->Capacity;
}

/*入队*/ 
void Enqueue( int x, Queue Q )
{
	if ( IsFull( Q ) )
		printf( "Full Queue" );
	else
	{
		Q->Size++;
		Q->Rear = Succ( Q->Rear, Q );
		Q->Array[Q->Rear] = x;
	}
}

/*创建队列*/ 
Queue CreateQueue( int MaxElements )
{
	if ( MaxElements < MinQueueSize )
	{
		printf("Size too small");
		return NULL;
	}
	Queue Q;
	Q = (Queue)malloc( sizeof ( struct QueueRecord ) );
	Q->Array = (int *)malloc( sizeof ( int ) * MaxElements );
	if ( Q == NULL )
	{
		printf("Out of space");
		return NULL;
	}
	else if ( Q->Array == NULL )
	{
		printf("Out of space");
		return NULL;
	}
	else
	{
		Q->Capacity = MaxElements;
		MakeEmpty( Q );
		return Q;
	}
}

/*出队*/ 
void Dequeue( Queue Q )
{
	if ( IsEmpty( Q ) )
		printf("Empty Queue");
	else
		Q->Front = Succ( Q->Front, Q );
		Q->Size--;
}

/*返回队头元素并出队*/ 
int  FrontAndDequeue( Queue Q )
{
	int x;
	if( IsEmpty( Q ) )
	{
		printf("空队列");
		return 1;
	}
	else
	{
		x = Q->Array[Q->Front];
		Dequeue ( Q );
		return x;
	}
}

/*返回队头元素*/
int Front(  Queue Q )
{
	return Q->Array[Q->Front];
}

int main()
{
	int size=0;
	int MaxElements;
	int x;
	Queue Q;
	printf( "请输入你要创建的队列的大小：" );
	scanf( "%d", &MaxElements );
	Q = CreateQueue( MaxElements );
	if( Q== NULL )
		return 1;
	while ( !IsFull( Q ) )
	{
		printf( "请输入第%d个元素", size+1);
		scanf( "%d", &x);
		Enqueue( x, Q );
		size++;
	}
	Dequeue( Q );
	printf( "执行一次出队操作后 ，队头元素是 ：%d\n", Front( Q ) );
	printf( "这%d个元素为：", size-1);
	while ( !IsEmpty( Q ) )
	{
		x = FrontAndDequeue( Q );
		printf( "%d  ", x );
	}
	MakeEmpty( Q );
	return 0;
}
