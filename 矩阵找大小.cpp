#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 30
int main()
{
    int a[N],i,max,min,t,h,l;
    srand((int)time(NULL));a[0]=rand()%32767;//���һ������� 
    max=min=a[0];h=l=0;printf("%6d",a[0]);
    for(i=1;i<N;i++)
    {
        a[i]=rand()%32767;//���һ������� 
        if(max<a[i]){max=a[i];h=i;}//�ж����ֵ����¼�±� 
        if(min>a[i]){min=a[i];l=i;}//�ж���Сֵ����¼�±� 
        if((i+1)%5)printf("%6d",a[i]);else printf("%6d\n",a[i]);//��5�����ͻ�һ�� 
    }
    printf("\n");
    t=a[0];a[0]=a[h];a[h]=t;//�����Ļ�����һ�� 
    t=a[N-1];a[N-1]=a[l];a[l]=t;//����С�Ļ������һ�� 
    for(i=0;i<N;i++)if((i+1)%5)printf("%6d",a[i]);else printf("%6d\n",a[i]);printf("\n");
}
