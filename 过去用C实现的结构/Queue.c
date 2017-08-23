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

/*�ж϶����Ƿ�Ϊ��*/ 
int IsEmpty( Queue Q )
{
	return Q->Size == 0;
}

/*ʹ����Ϊ��*/ 
void MakeEmpty( Queue Q )
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

/*���ƶ�ͷ��β���±�*/ 
static int Succ( int value, Queue Q)
{
	if( ++value == Q->Capacity )
		value = 0;
	return value;
}

/*�ж��Ƿ���������*/ 
int IsFull( Queue Q )
{
	return Q->Size == Q->Capacity;
}

/*���*/ 
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

/*��������*/ 
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

/*����*/ 
void Dequeue( Queue Q )
{
	if ( IsEmpty( Q ) )
		printf("Empty Queue");
	else
		Q->Front = Succ( Q->Front, Q );
		Q->Size--;
}

/*���ض�ͷԪ�ز�����*/ 
int  FrontAndDequeue( Queue Q )
{
	int x;
	if( IsEmpty( Q ) )
	{
		printf("�ն���");
		return 1;
	}
	else
	{
		x = Q->Array[Q->Front];
		Dequeue ( Q );
		return x;
	}
}

/*���ض�ͷԪ��*/
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
	printf( "��������Ҫ�����Ķ��еĴ�С��" );
	scanf( "%d", &MaxElements );
	Q = CreateQueue( MaxElements );
	if( Q== NULL )
		return 1;
	while ( !IsFull( Q ) )
	{
		printf( "�������%d��Ԫ��", size+1);
		scanf( "%d", &x);
		Enqueue( x, Q );
		size++;
	}
	Dequeue( Q );
	printf( "ִ��һ�γ��Ӳ����� ����ͷԪ���� ��%d\n", Front( Q ) );
	printf( "��%d��Ԫ��Ϊ��", size-1);
	while ( !IsEmpty( Q ) )
	{
		x = FrontAndDequeue( Q );
		printf( "%d  ", x );
	}
	MakeEmpty( Q );
	return 0;
}
