#include<stdio.h>   
// ����һ�꼶С������һ������Ϸ��С������һ��һλ��������������Ҫ��+��-��*��/��%����С��Ҫ�ҳ���Щ�����е����ֵ����Сֵ��Ȼ����С����Ҫ��������������С��������������Ľ�������룺    �ö��ŷָ���һλ���������У�����������͵Ⱥ����������� op ��С��=��� 
 int main()   
  {    
  int op=0; int max=0; int min=9;    
  for(;1;)   
   {    
   char c;    
   scanf("%c",&c);    
   if(c==',') continue;   
    if(c=='+') op=1;    
    else if(c=='-') op=2;    
 else if(c=='*') op=3;    
 else if(c=='/') op=4;    
 else if(c=='%') op=5;    
 else if(c=='=') {break;}    
  else if(c<='9'&&c>='0')   
   { if((c-'0')>max) {max=c-'0';} if((c-'0')<min){min=c-'0';} } }    
  switch (op)   
     { case 1: { printf("%d+%d=%d\n",max,min,max+min); break; }    
   case 2: { printf("%d-%d=%d\n",max,min,max-min); break; }    
  case 3: { printf("%d*%d=%d\n",max,min,max*min); break; }    
  case 4: { if(min==0) printf("Error!\n");    
  else { printf("%d/%d=%d\n",max,min,max/min); } break; }    
   case 5: { if(min==0) printf("Error!\n");    
 else { printf("%d%%%d=%d\n",max,min,max%min); } break; }   
  }   
  }  
