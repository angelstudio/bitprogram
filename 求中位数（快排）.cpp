#include<stdio.h>  
#include<stdlib.h> 
int y[1000000]; 
int cmp(const void *p,const void *q)//�ú������е���������ţ������Ҫ���н�����ţ���1��-1�������� 
  { 
      return *(int *)p<*(int *)q?1:-1;//����Ԫ�ص�ֵ�������� 
    } 
 
int main() 
{ 
    int x;int n=0,i=0; 
 while(scanf("%d,%d",&x,&y[i])!=EOF) 
        { 
        	n++; 
        	i++; 
       } 
  qsort(y,n,sizeof(y[0]),cmp); 
   printf("%d\n",y[n/2]); 
}  
