#include<stdio.h>
#include<stdlib.h>


/*	
	带有表头的单向链表
*/ 
	


struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreateList();
List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position p, List L );
Position Find( int x, List L );
void Delete( int x, List L );
Position FindPrevious( int x, List L );
void Insert( int x, List L, Position p);
void DeleteList( List L );
void PrintList( List L );
Position Header( List L );
Position First( List L );
Position Advance( Position p );



struct Node
{
	int element;
	Position next;
};

int n;//节点总数 

/* Return true if L is Empty */
int IsEmpty( List L )
{
	return L->next == NULL;
}


/* Return true if P is the last position in List L
   Parameter L is unused in this implementation */
int IsLast( Position p, List L )
{
	return p->next == NULL;
}

/* Return Position of X in L; null is not Found */
Position Find( int x, List L)
{
	Position p; 
	p = L->next;
	while( p != NULL && p->element !=x )
		  p = p->next;
	return p; 
}

/* Delete first occurrence of x from a list
   Assume use of a header node */
void Delete( int x, List L )
{
	Position p, TmpCell;
	p=FindPrevious( x, L );
	if ( !IsLast( p, L ) ) /*Assumption of header use
	   	 		  	   	     X is found;delete it*/
    {
    	TmpCell = p->next;
    	p->next = TmpCell->next; //Bypass deleted cell
    	free( TmpCell );
	}
}

/* If X is not found,then next field of returned
   Position is null
   Assumes a header */
Position FindPrevious( int x, List L )
{
	Position p;
	p = L;
	while ( p->next != NULL && p->next->element != x)
		  p = p->next;
    return p;
}

/* Insert (after legal position p)
   Header implementation assumed
   Parameter L is unused in this implementation */
void Insert( int x, List L, Position p )
{
	Position TmpCell;
	
	TmpCell = (Position)malloc( sizeof( struct Node ) );
	if( TmpCell == NULL )
		printf("Out of space!!");
	
	TmpCell->element = x;
	TmpCell->next = p->next;
	p->next = TmpCell;
}

/* Correct DeleteList algorithm */
void DeleteList( List L )
{
	Position p, Tmp;
	p = L->next;  //Header assumed
	L->next = NULL;
	while ( p != NULL )
	{
		Tmp = p->next;
		free( p );
		p = Tmp;
	}
}

int n; //节点总数

/*创建链表*/ 
List CreateList()
{
	List L = NULL; //头结点
	Position p1 = NULL; //p1保存新创建的节点的位置
	Position p2 = NULL; //p2保存原链表最后一个节点的位置 
	
	printf("==============================\n");
	printf("|          创建链表          |\n");
	printf("|         输入0结束          |\n");
	printf("==============================\n"); 
	n = 0; //创建前链表的节点总数为0：空链表
	p1 = (Position)malloc( sizeof( struct Node ) );//开辟一个新节点
	p2 = p1;	//如果节点开辟成功，p2先把p1指针保存下来已备后用
	L = (Position)malloc( sizeof( struct Node ) );		//表头，假想的单元，不存储element 
	
	if( p1 == NULL )	//节点开辟不成功
	{
		printf("节点开辟不成功");
		return NULL;
	}
	else
	{
		L->next = NULL;	//开始head指向NULL 
		printf( "请输入第%d个节点 -- element:\t", n+1 );
		scanf( "%d", &( p1->element) );
	} 
	
	while( p1->element != 0 )   //只要element不为0，就继续录入下一个节点
	{
		n += 1;		//节点数+1
		if ( n == 1 )	//如果节点总数是1，则head指向刚创建的节点p1
		{
			L->next = p1;
			p2->next = NULL;	//此时的p2就是p1，也就是p1->next=NUL 
		} 
		else
		{
			p2->next = p1;	//指向上次刚刚开辟的新节点 
		}
		p2 = p1;
		p1 = (Position)malloc( sizeof( struct Node ) );
		printf("请输入第%d个节点 -- element:\t", n+1 );
		scanf( "%d", &( p1->element ) );
	} 
	p2->next = NULL;	//单向列表最后一个节点指向NULL 
	free( p1 );			//释放p1 
	return L;		//返回创建链表的头指针 
} 


void PrintList( List L )
{
	Position p = NULL;
	p = L->next;		//L是表头
	printf("\n 这%d个数据分别为:\n", n);		//n在CreateList()结束时，值为节点数+1
	while( p != NULL )
	{
		printf( "%o\t%d\t%o\n", p, p->element, p->next);		//当前节点的位置，字段值，下一节点的位置
		p = p->next;	//移到下一节点 
	} 
}


int main()
{
	return 0;
}



