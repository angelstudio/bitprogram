#include <stdio.h>
#include<stdlib.h>
void revstr ( char * s )
{
	char *p = s, c;
	while (*p!='\0' ) /*��p�ƶ����ַ���β��*/
    p++;
	p--;           
  	if ( s < p )
  	{
		c = *s;
		*s=*p;
		*p = '\0';
		revstr(s+1);
 		*p=c;
	}
}

int main()
{
	char  a[10]={"Sunday"};
	revstr( a );
	printf("%s",a);
	system("pause");
}

