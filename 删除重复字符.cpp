#include<stdio.h>
int main()
{ 
	char c[100];
	int i,k,p,q,r;
	gets(c);
	for(i=0;c[i]!='\0';i++)
	{
		loop:for(k=i+1;c[k]!=0;)//������ 
		if(c[i]==c[k])//�ж��Ƿ�����ͬԪ�� 
		{
		for(p=k;p<98;p++)//����ͬԪ�أ����ú�ߵ�Ԫ�ظ��� 
		c[p]=c[p+1];
		goto loop;//������ԭλ�ü���Ƿ�����ͬԪ�� 
		}
		else 
		k++; 
	}
	puts(c);
} 
//��һ���㷨 
//#include<stdio.h>
//#include <string.h>
//int main()
//{char str1[100], str2[100];  int i, j, n;
// printf ("Enter string:");
// gets ( str1 );
// n = 0;
// for ( i=0; str1[i]!='\0'; i++)
//   { for (j=0;j<n;j++)
//        if(str1[i]==str2[j])
//           break; 
//     if ( j == n )     /* ���ظ����򿽱� */
//        str2 [ n++ ] = str1 [ i ];  
//   }
//  str2[n]='\0';
//  printf("Result:");
//  puts ( str2 );
//} 
