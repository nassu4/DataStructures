#include<stdio.h>
#include<stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef PtrToNode Position;

int IsEmpty( Stack s );
Stack CreateStack();
void Push( int x, Stack s );
void Pop( Stack s );
int Top( Stack s );
void MakeEmpty( Stack s );

struct Node
{
	int x;
	Position next;
}; 

/*�ж��Ƿ��ǿ�ջ*/ 
int IsEmpty( Stack s )
{
	return s->next == NULL;
}

/*��ջ*/ 
Stack CreateStack()
{
	Stack s;
	s = (Stack)malloc( sizeof( struct Node ) );		//ͷָ�� 
	if ( s==NULL )
	{
		printf( "Out of space" );
		return NULL;
	}
	s->next = NULL;
	MakeEmpty( s );
	return s;
}

/*���ջ*/ 
void MakeEmpty ( Stack s )
{
	if( s == NULL )
	{
		printf( "Must use CreateStack first" );
	}
	else
	{
		while( !IsEmpty )		//���ϵس�ջ 
		{
			Pop( s );
		}
	}
}

/*��ջ*/ 
void Pop( Stack s )
{
	Position Tmp = NULL;
	if ( IsEmpty( s ) )
	{
		printf("Empty Stack");
	}
	else
	{
		Tmp = s->next;
		s->next = Tmp->next;
		free ( Tmp );
	} 
	
	
}

/*��ջ*/ 
void Push( int x, Stack s )
{
	Position Tmp;
	Tmp = (Position)malloc( sizeof( struct Node ) );
	if ( Tmp == NULL )
	{
		printf("Out of space");
	}
	else
	{
		Tmp->x = x;
		Tmp->next = s->next;
		s->next = Tmp;
	}
}

/*����ջ��Ԫ��*/ 
int Top( Stack s )
{
	if ( IsEmpty( s ) )
	{
		printf( "Empty Stack" );
		return 0;
	}
	else
	{
		return s->next->x;
	}
}

int i;		//ջ��Node�ĸ��� 

/*��ӡջ*/
void PrintStack( Stack s )
{
	Position Tmp;
	Tmp = s->next;
	while ( i-- > 0 )
	{
		printf( "%d    ", Tmp->x );
		Tmp = Tmp->next;
	}
} 

	
/*����*/ 
int main()
{
	int x;		//ջ�е�Ԫ�� 
	int n; 
	Stack s;
	s = CreateStack();
	printf( "�������뼸��Ԫ��?" );
	scanf( "%d", &n );
	for ( i = 0; i < n; i++)
	{
		printf( "�������%d��Ԫ��:\t", i+1 );
		scanf( "%d", &x );
		Push( x, s );
	}
	printf( "��%d��Ԫ����: ", i );
	PrintStack( s );
	return 0;
}
