#include<stdio.h>
#include<stdlib.h>


/*	
	���б�ͷ�ĵ�������
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

int n;//�ڵ����� 

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

int n; //�ڵ�����

/*��������*/ 
List CreateList()
{
	List L = NULL; //ͷ���
	Position p1 = NULL; //p1�����´����Ľڵ��λ��
	Position p2 = NULL; //p2����ԭ�������һ���ڵ��λ�� 
	
	printf("==============================\n");
	printf("|          ��������          |\n");
	printf("|         ����0����          |\n");
	printf("==============================\n"); 
	n = 0; //����ǰ����Ľڵ�����Ϊ0��������
	p1 = (Position)malloc( sizeof( struct Node ) );//����һ���½ڵ�
	p2 = p1;	//����ڵ㿪�ٳɹ���p2�Ȱ�p1ָ�뱣�������ѱ�����
	L = (Position)malloc( sizeof( struct Node ) );		//��ͷ������ĵ�Ԫ�����洢element 
	
	if( p1 == NULL )	//�ڵ㿪�ٲ��ɹ�
	{
		printf("�ڵ㿪�ٲ��ɹ�");
		return NULL;
	}
	else
	{
		L->next = NULL;	//��ʼheadָ��NULL 
		printf( "�������%d���ڵ� -- element:\t", n+1 );
		scanf( "%d", &( p1->element) );
	} 
	
	while( p1->element != 0 )   //ֻҪelement��Ϊ0���ͼ���¼����һ���ڵ�
	{
		n += 1;		//�ڵ���+1
		if ( n == 1 )	//����ڵ�������1����headָ��մ����Ľڵ�p1
		{
			L->next = p1;
			p2->next = NULL;	//��ʱ��p2����p1��Ҳ����p1->next=NUL 
		} 
		else
		{
			p2->next = p1;	//ָ���ϴθոտ��ٵ��½ڵ� 
		}
		p2 = p1;
		p1 = (Position)malloc( sizeof( struct Node ) );
		printf("�������%d���ڵ� -- element:\t", n+1 );
		scanf( "%d", &( p1->element ) );
	} 
	p2->next = NULL;	//�����б����һ���ڵ�ָ��NULL 
	free( p1 );			//�ͷ�p1 
	return L;		//���ش��������ͷָ�� 
} 


void PrintList( List L )
{
	Position p = NULL;
	p = L->next;		//L�Ǳ�ͷ
	printf("\n ��%d�����ݷֱ�Ϊ:\n", n);		//n��CreateList()����ʱ��ֵΪ�ڵ���+1
	while( p != NULL )
	{
		printf( "%o\t%d\t%o\n", p, p->element, p->next);		//��ǰ�ڵ��λ�ã��ֶ�ֵ����һ�ڵ��λ��
		p = p->next;	//�Ƶ���һ�ڵ� 
	} 
}


int main()
{
	return 0;
}



