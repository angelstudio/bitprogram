#include "stdio.h"  
int main()  
{  
    int i, j, k, n;  
    char ch;  
    scanf("%c %d", &ch, &n);  
    getchar();     
    //������  
    for (i = 1; i <= n; i++)  
    {  
        //ǰ��ո񲿷�  
        for (j = 1; j <= n-i; j++)  
        {  
            printf(" ");  
        }  
        //��һ��,һ���ַ�  
        if (i==1)  
        {  
            printf("%c\n", ch++);  
            continue;  
        }  
        //����ַ�  
        printf("%c", ch);  
        //�м�ո�  
        for (k = 1; k <= i*2-3; k++)  
        {  
            printf(" ");  
        }  
        //�ұ��ַ�  
        printf("%c\n", ch++);  
    }  
  
    // ������ 
	ch-=2 ;
    for (i = n-1; i >=1 ; i--)  //��������ǣ�ֻ����һ������иĶ�  
    {  
        //ǰ��ո񲿷�  
        for (j = 1; j <= n-i; j++)  
        {  
            printf(" ");  
        }  
        //���һ��,һ���ַ�  
        if (i==1)  
        {  
            printf("%c\n", ch--);  
            continue;  
        }  
        //����ַ�  
        printf("%c", ch);  
        //�м�ո�  
        for (k = 1; k <= i*2-3; k++)  
        {  
            printf(" ");  
        }  
        //�ұ��ַ�  
        printf("%c\n", ch--);  
    }  
    return 0;   
}  
