#include<stdio.h>
#include<math.h>
main()
{
	float a,b,c,d,x1,x2,m,n;
	printf("�����뷽�̵�ϵ��a,b,c\n");
	scanf("%f%f%f",&a,&b,&c);
	d=b*b-4*a*c;
	if (d>=0)
	{
    x1=(-b+sqrt(d)/(2*a));
	x2=(-b-sqrt(d)/(2*a));
	printf("��һԪ���η��̵�ʵ����Ϊx1=%f,x2=%f",x1,x2);
    }
	else
	{
	m=-b/(2*a);//���ʵ������ 
	n=sqrt(-d)/(2*a);//����������� 
	printf("��һԪ���η��̵�������Ϊx1=%.2f+%.2fi,",m,n);
	printf("x2=%.2f-%.2fi",m,n);
    }	
	return 0; 
} 
