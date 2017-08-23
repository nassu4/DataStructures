#include<stdio.h>
#include<stdlib.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef Position SearchTree;

SearchTree MakeEmpty( SearchTree T );
Position Find( int x, SearchTree T );
Position FindMin( SearchTree T );
Position FindMax( SearchTree T );
SearchTree Insert( int x, SearchTree T );
SearchTree Delete( int x, SearchTree T );


struct TreeNode
{
	int x;
	Position Left;
	Position Right;
};

/*��ն�����*/
SearchTree MakeEmpty( SearchTree T )
{
	if ( T != NULL )
	{
		MakeEmpty( T->Left );
		MakeEmpty( T->Right );
		free( T );
	}
	return NULL;
}

/*Ѱ��elementΪx�Ľڵ�*/
Position Find( int x, SearchTree T )
{
	if ( T == NULL )
		return NULL;
	if ( x < T->x )
		return ( x, T->Left );
	else if ( x > T->x )
		return ( x, T->Right );
	else return T;
}

/*Ѱ�Ҷ������е���Сֵ�Ľڵ�*/
Position FindMin( SearchTree T )
{
	if ( T == NULL )
		return NULL;
	else if	( T->Left == NULL )
		return T;
	else 
		return FindMin( T->Left );
}

/*Ѱ�Ҷ������е����ֵ�Ľڵ�*/
Position FindMax( SearchTree T )
{
	if ( T == NULL )
		return NULL;
	else if ( T->Right == NULL )
		return T;
	else return FindMax( T->Right );
}

/*����һ���µĽڵ㣬����������оͲ�����*/
SearchTree Insert( int x, SearchTree T )
{
	if ( T == NULL )
	{
		/*����һ����*/   
		T = (SearchTree)malloc( sizeof ( struct TreeNode ) );
		if ( T == NULL )
			{
				printf( "Out of space" );
				return NULL;
			} 
		else
			{
				T->x = x;
				T->Left = T->Right = NULL;
			}
	}
	else
	{
		if ( x < T->x )
			T->Left = Insert( x, T->Left );
		else if ( x > T->x )
			T->Right = Insert( x, T->Right );
	}
	return T;
}

/*ɾ��һ��elementΪx�Ľڵ�*/
SearchTree Delete( int x, SearchTree T )
{
	Position TmpCell;
	if ( T == NULL )
	{
		printf("Element not found");
		return T;
	}
	else if ( x < T->x )    //go left
		T->Left = Delete( x, T->Left );
	else if ( x > T->x )    //go right
		T->Right = Delete( x, T->Right );
	else if ( T->Left && T->Right )   //two children
	{
		TmpCell = FindMin( T->Right );     //Ѱ�ҵ�Ҫɾ���ڵ���������е���Сֵ
		T->x = TmpCell->x;
		T->Right = Delete( T->x, T->Right); 
	}
	else     //one or zero child
	{
		TmpCell = T;
		if ( T->Left == NULL )  //Also handles 0 child
			T = T->Right;
		else if ( T->Right == NULL )
			T = T->Left;
		free( TmpCell );
	}
	return T;
} 


int main()
{
	Position p = NULL;
	SearchTree T = NULL ;
	MakeEmpty(T); //��ʼ�� 
	int x;		//element 
	int i;		//ѭ������ 
	int n;		//�ڵ��� 
	printf("������ʼ���ڵ���:");
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		printf( "�������%d��ֵ��", i+1 );
		scanf( "%d" ,&x);
		T = Insert( x, T );		//��ʼʱT��NULL����Ҫ��ֵ 
	 } 
	p = FindMax( T );
	printf("���ֵ��:  %d\n", p->x );
	p = FindMin( T );
	printf("��Сֵ�ǣ� %d\n", p->x );
	return 0;
}










