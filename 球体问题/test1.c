#include<stdio.h>
#include<math.h> 
int main()
{
	double R1,R2,d,w,s0,pi,s1,s,s2,H1,H2,h1,h2,v1,v2,v0,v,p;
	int N,i; 
	scanf("%d",&N);
	pi=2*acos(0.0);
	for(i=0;i<N;i++)
		{
			scanf("%lf%lf%lf%lf%lf",&R1,&R2,&d,&w,&s);
			s0=4*pi*(R1*R1+R2*R2);//�������� 
			h1=(R2*R2-R1*R1-d*d)/(-2*d);//�������Ҷ����Ƶ��� 
			h2=(R1*R1-R2*R2-d*d)/(-2*d);
			H1=R1-h1;
			H2=R2-h2;
			s1=2*pi*R1*H1;//��ȱ��ʽ 
			s2=2*pi*R2*H2;
			s=s0-s1-s2;//��ȥ�ظ����� 
			v1=pi*H1*H1*(R1-H1/3);//������ȱ��ʽ���������� 
			v2=pi*H2*H2*(R2-H2/3);
			v0=4.0/3*pi*(R1*R1*R1+R2*R2*R2);//����� 
			v=v0-v1-v2;
			printf("%.4lf %.4lf\n",v,s);
			p=w/v*1000;
			if(p>s)
			printf("The Paired-Sphere Sinks.\n");
			else
			printf("The Paired-Sphere Floats.\n");
		}
}
