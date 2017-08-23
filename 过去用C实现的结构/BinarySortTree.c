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

/*清空二叉树*/
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

/*寻找element为x的节点*/
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

/*寻找二叉树中的最小值的节点*/
Position FindMin( SearchTree T )
{
	if ( T == NULL )
		return NULL;
	else if	( T->Left == NULL )
		return T;
	else 
		return FindMin( T->Left );
}

/*寻找二叉树中的最大值的节点*/
Position FindMax( SearchTree T )
{
	if ( T == NULL )
		return NULL;
	else if ( T->Right == NULL )
		return T;
	else return FindMax( T->Right );
}

/*插入一个新的节点，如果发现已有就不插入*/
SearchTree Insert( int x, SearchTree T )
{
	if ( T == NULL )
	{
		/*创建一个树*/   
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

/*删除一个element为x的节点*/
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
		TmpCell = FindMin( T->Right );     //寻找到要删除节点的右子树中的最小值
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
	MakeEmpty(T); //初始化 
	int x;		//element 
	int i;		//循环控制 
	int n;		//节点数 
	printf("输入起始化节点数:");
	scanf("%d",&n);
	for ( i = 0; i < n; i++ )
	{
		printf( "请输入第%d个值：", i+1 );
		scanf( "%d" ,&x);
		T = Insert( x, T );		//开始时T是NULL，需要赋值 
	 } 
	p = FindMax( T );
	printf("最大值是:  %d\n", p->x );
	p = FindMin( T );
	printf("最小值是： %d\n", p->x );
	return 0;
}










