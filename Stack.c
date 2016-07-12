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

/*判断是否是空栈*/ 
int IsEmpty( Stack s )
{
	return s->next == NULL;
}

/*建栈*/ 
Stack CreateStack()
{
	Stack s;
	s = (Stack)malloc( sizeof( struct Node ) );		//头指针 
	if ( s==NULL )
	{
		printf( "Out of space" );
		return NULL;
	}
	s->next = NULL;
	MakeEmpty( s );
	return s;
}

/*清空栈*/ 
void MakeEmpty ( Stack s )
{
	if( s == NULL )
	{
		printf( "Must use CreateStack first" );
	}
	else
	{
		while( !IsEmpty )		//不断地出栈 
		{
			Pop( s );
		}
	}
}

/*出栈*/ 
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

/*进栈*/ 
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

/*返回栈顶元素*/ 
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

int i;		//栈中Node的个数 

/*打印栈*/
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

	
/*测试*/ 
int main()
{
	int x;		//栈中的元素 
	int n; 
	Stack s;
	s = CreateStack();
	printf( "你想输入几个元素?" );
	scanf( "%d", &n );
	for ( i = 0; i < n; i++)
	{
		printf( "请输入第%d个元素:\t", i+1 );
		scanf( "%d", &x );
		Push( x, s );
	}
	printf( "这%d个元素是: ", i );
	PrintStack( s );
	return 0;
}
