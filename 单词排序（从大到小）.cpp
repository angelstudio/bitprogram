#include<string.h>
#include<stdio.h> 
#define N 5
int main()
{
 char words[N][15],temp[15]={0};
 int i,j,k;
 scanf("%s",words[0]);//�����һ���ַ��� 
 for (i=1;i<N;i++)
    {   scanf("%s",words[i]);//����ڶ����ַ��� 
		j=i; 
        while(strcmp(words[j],words[j-1])>0&&j>0)//�ַ����Ƚϣ����������Ĵ���Ϊ���� 
            {
            	strcpy(temp,words[j-1]);//��ǰһ���ַ�����temp��ȥ
                strcpy(words[j-1],words[j]);//���������Ĵ���ô��������Ŀ�����ǰ�� 
                strcpy(words[j],temp);//��һ����temp��ֵ 
                j--;
            } 

    }
    for (i=0;i<N;i++)//ѭ����ɺ������� 
        printf("%s\n",words[i]);
    }
