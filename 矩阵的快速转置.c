#define MAXSIZE 12500
#include<stdio.h>
int num[MAXSIZE],cpot[MAXSIZE];
typedef  struct {
        int   i, j;              // �÷���Ԫ�� ���±� �� ���±�
        int  e;     // ����Ԫֵ
  } Triple;      // ��Ԫ������

typedef  struct {
       Triple data [ MAXSIZE+1 ];  // �洢��Ԫ���data[0]δ��
       int   mu, nu, tu;  // �����������ͷ���Ԫ����
  } TSMatrix;      // ϡ���������

TSMatrix M,T;

void FastTransMatrix(TSMatrix a, TSMatrix b)
{//������Ԫ��˳���洢ϡ�������M��ת�þ���T
    T.mu=M.nu;  T.nu=M.mu;  T.tu=M.tu;
    int col,t,p,q,i;
        if ( T.tu )
        {
            for ( col=1; col<=M.nu; ++col )  // ��ʼ������
                num[ col ] = 0;
            // ��M��ÿһ�з���Ԫ����
            for ( t=1; t<=M.tu; ++t )    // ��2��
                ++ num[ M.data[t].j ];       //��� col���е�һ������Ԫ��T.data�е����
            printf("num:");
            for(i=1;i<=M.nu;++i)
                printf("%d,",num[i]);
            cpot[ 1 ] = 1;
            for ( col=2; col<=M.nu;  ++col )   // ��3��
                cpot[ col ] = cpot[ col-1 ] + num[ col-1 ];
            printf("\ncpot:1,");
            for(i=2;i<=M.nu;++i)
                printf("%d,",cpot[i]);
            printf("\n");
            for ( p=1; p<=M.tu;  ++p )    // ��4��
            {
                col = M.data[ p ].j;
                q = cpot[ col ];
                T.data[ q ].i = M.data[ p ].j;
                T.data[ q ].j = M.data[ p ].i;
                T.data[ q ].e = M.data[ p ].e;
                ++ cpot[ col ];
            } // for
        }  // if
}  // FastTranMatrix

int main()
{
    int a,b,c,i,n=1,tmp1,tmp2;
    scanf("%d %d %d",&M.mu,&M.nu,&M.tu);
    tmp2=tmp1=M.tu;
    while(tmp1--)
    {
        scanf("%d %d %d",&a,&b,&c);
        M.data[n].i=a;
        M.data[n].j=b;
        M.data[n].e=c;
        n++;
    }
    FastTransMatrix(M,T);
    n=1;
    while(tmp2--)
    {
        printf("%d,%d,%d\n",T.data[n].i,T.data[n].j,T.data[n].e);
        n++;
    }
}
