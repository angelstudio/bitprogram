#include <stdio.h>
#include <time.h>
main()
{
 struct tm *tm1;
 struct tm tm;
 time_t t;
 int n;
 printf("������Ҫ�������ݣ�");
 scanf("%d", &n);
 tm.tm_year = n - 1900;
 tm.tm_mon = 4;
 tm.tm_mday = 1;
 tm.tm_hour = tm.tm_min = tm.tm_sec = 0;
 t = mktime(&tm);
 tm1 = localtime(&t);
 n = 15 - tm1->tm_wday;
 if (n == 15)
  n = n - 7;
 printf("��һ���ĸ�׽��������ǣ�5��%d��\n", n);
}
