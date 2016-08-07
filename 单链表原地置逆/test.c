/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

// ����ԭ�ط���
#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define FMT "%d"

typedef struct  Lnode {
	ElemType       data;  		// ������
	struct Lnode   * next;  	// ָ����
 } LNode, * LinkList;

LinkList L;

LinkList createListR( ElemType );
void OutList( LinkList );
void inverse( LinkList );

int main()
{
	LinkList Head;

	Head = createListR( -1 );
	inverse( Head );
	OutList( Head );
	return 0;
}

LinkList createListR( ElemType finish )
{
	ElemType x;
    LinkList first, s, rear;

	first = ( LinkList ) malloc(sizeof(LNode)); // ����ͷ���
	rear = first;   	 						// rear ָ���β
    scanf(FMT, &x);
    while ( x != finish )
	{  	s = ( LinkList )malloc(sizeof(LNode)); 	// �����½��
        s->data = x;
        rear->next = s;
		rear = s;   							// ���뵽��β
        scanf(FMT, &x);
    }
    rear->next = NULL;
    return first;
}

void OutList( LinkList first )
{
	while ( first->next!=NULL )
	{
		printf(FMT, first->next->data);
		printf("\n");
		first = first->next;
	}
}

void inverse( LinkList L )
{
    LinkList p,q,temp;
    p=L->next;
	temp=p->next;
	p->next=NULL;
	while(temp)
	{
		q=temp;
		temp=temp->next;
		q->next=p;
		p=q;
	}
	L->next=p;
}


